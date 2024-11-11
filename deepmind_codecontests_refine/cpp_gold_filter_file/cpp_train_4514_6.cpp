#include <bits/stdc++.h>
using namespace std;
const int MAX = 130;
long long dp[MAX][2], dt[MAX];
int slen;
char s[MAX];
struct node {
  int ty;
  char c;
  int cnt;
  void print() { printf("(ty=%d,c=%c,cnt=%d) ", ty, c, cnt); }
};
node tmp[MAX];
int tnt;
node li[MAX];
int lnt;
int main() {
  scanf("%s", s);
  for (int i = (1); i <= (90); ++i) {
    if (i == 1)
      dp[i][0] = dp[i][1] = 1;
    else {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }
  }
  for (int i = (1); i <= (90); ++i) dt[i] = dp[i][0] + dp[i][1];
  slen = strlen(s);
  int fb = -1;
  for (int i = (0); i <= (slen - 1); ++i)
    if (s[i] == 'B') {
      fb = i;
      break;
    }
  if (fb == -1) {
    printf("%d\n", 1);
  } else {
    bool hasA = 0;
    for (int i = (0); i <= (slen - 1); ++i)
      if (s[i] == 'A') {
        hasA = 1;
        break;
      }
    if (!hasA)
      printf("%d\n", 1);
    else {
      int pos = fb;
      tnt = 0;
      do {
        int nxt = (pos + 1) % slen;
        if (s[pos] == 'A') {
          tmp[tnt].ty = 0, tmp[tnt].c = 'A';
          tnt++;
          pos = nxt;
        } else {
          if (nxt == fb || s[nxt] == 'B') {
            tmp[tnt].ty = 0;
            tmp[tnt].c = s[pos];
            tnt++;
            pos = nxt;
          } else {
            tmp[tnt].ty = 1;
            tnt++;
            pos = (nxt + 1) % slen;
          }
        }
      } while (pos != fb);
      int ty0 = -1;
      for (int i = (0); i <= (tnt - 1); ++i) {
        if (tmp[i].ty == 0) {
          ty0 = i;
          break;
        }
      }
      if (ty0 == -1) {
        if (tnt == 2)
          printf("%d\n", 2);
        else if (tnt == 3)
          printf("%d\n", 4);
        else
          printf("%lld\n", dt[tnt - 1] + dt[tnt - 3]);
      } else {
        lnt = 0;
        int pos = ty0;
        do {
          int nxt = (pos + 1) % tnt;
          if (tmp[pos].ty == 0) {
            li[lnt] = tmp[pos];
            lnt++;
            pos = nxt;
          } else {
            int j = nxt;
            int cnt = 1;
            while (j != ty0 && tmp[j].ty == 1) {
              cnt++, j = (j + 1) % tnt;
            }
            li[lnt].ty = 1;
            li[lnt].cnt = cnt;
            lnt++;
            pos = j;
          }
        } while (pos != ty0);
        bool yab = 0;
        int fty1;
        for (int i = (0); i <= (lnt - 1); ++i)
          if (li[i].ty == 1) {
            fty1 = i;
            break;
          };
        pos = fty1;
        do {
          int j = (pos + 1) % lnt;
          while (li[j].ty == 0) j = (j + 1) % lnt;
          int nxt = j;
          j = ((j - 1) % lnt + lnt) % lnt;
          int k = (pos + 1) % lnt;
          while (k != j) {
            int nxtk = (k + 1) % lnt;
            if (li[k].c == 'A' && li[nxtk].c == 'B') {
              yab = 1;
              break;
            }
            k = nxtk;
          }
          if (yab == 1) break;
          pos = nxt;
        } while (pos != fty1);
        if (yab)
          printf("%d\n", 0);
        else {
          long long ans = 1;
          for (int i = (0); i <= (lnt - 1); ++i) {
            if (li[i].ty == 1) {
              int prev = ((i - 1) % lnt + lnt) % lnt, nxt = (i + 1) % lnt;
              bool hb = li[prev].c == 'A', tb = li[nxt].c == 'B';
              if (li[i].cnt == 1) {
                if (!hb && !tb) ans *= 2;
              } else {
                int tmp = li[i].cnt;
                if (hb) tmp--;
                if (tb) tmp--;
                if (tmp) ans *= dt[tmp];
              }
            }
          }
          printf("%lld\n", ans);
        }
      }
    }
  }
  return 0;
}
