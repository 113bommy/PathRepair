#include <bits/stdc++.h>
using namespace std;
int card[20][20][3];
bool exits[15][4];
pair<int, int> P[2];
pair<int, int> res[2];
vector<pair<int, int> > G;
char Jo[2][3];
bool flag;
int n, m;
int rank_(char *s) {
  if (s[0] >= '2' && s[0] <= '9') {
    return s[0] - '0';
  } else {
    if (s[0] == 'T') return 10;
    if (s[0] == 'J' && s[1] != '1' && s[1] != '2') return 11;
    if (s[0] == 'Q') return 12;
    if (s[0] == 'K') return 13;
    if (s[0] == 'A') return 1;
    if (s[0] == 'J') return 14;
  }
}
char rerank(int k) {
  if (k >= 2 && k <= 9) return k + '0';
  if (k == 1) return 'A';
  if (k == 10) return 'T';
  if (k == 11) return 'J';
  if (k == 12) return 'Q';
  if (k == 13) return 'K';
}
int suit(char *s) {
  if (s[1] == 'C') return 0;
  if (s[1] == 'D') return 1;
  if (s[1] == 'H') return 2;
  if (s[1] == 'S') return 3;
  if (s[1] == '1') return 0;
  if (s[1] == '2') return 1;
}
char resuit(int k) {
  if (k == 0) return 'C';
  if (k == 1) return 'D';
  if (k == 2) return 'H';
  if (k == 3) return 'S';
}
bool judge(int x1, int y1) {
  bool Ju[15];
  memset(Ju, false, sizeof(Ju));
  for (int i = x1; i < x1 + 3; i++)
    for (int j = y1; j < y1 + 3; j++) {
      if (Ju[card[i][j][0]]) {
        return false;
      } else {
        Ju[card[i][j][0]] = true;
      }
    }
  return true;
}
void solve() {
  for (int i = 1; i + 2 <= n; i++) {
    for (int j = 1; j + 2 <= m; j++) {
      for (int k = 1; k + 2 <= n; k++) {
        for (int e = j + 3; e + 2 <= m; e++) {
          if (judge(i, j) && judge(k, e)) {
            res[0].first = i, res[0].second = j;
            res[1].first = k, res[1].second = e;
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
      if (flag) break;
    }
    if (flag) break;
  }
  for (int i = 1; i + 2 <= n; i++) {
    for (int j = 1; j + 2 <= m; j++) {
      for (int k = i + 3; k + 2 <= n; k++) {
        for (int e = j; e + 2 <= m; e++) {
          if (judge(i, j) && judge(k, e)) {
            res[0].first = i, res[0].second = j;
            res[1].first = k, res[1].second = e;
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
      if (flag) break;
    }
    if (flag) break;
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    G.clear();
    memset(exits, false, sizeof(exits));
    int Joker = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char op[3];
        scanf("%s", op);
        int r = rank_(op);
        int s = suit(op);
        card[i][j][0] = r;
        card[i][j][1] = s;
        exits[r][s] = true;
        if (r == 14) {
          P[Joker].first = i;
          P[Joker].second = j;
          Jo[Joker][0] = op[0];
          Jo[Joker][1] = op[1];
          Jo[Joker][3] = '\0';
          Joker++;
        }
      }
    }
    for (int i = 1; i <= 13; i++) {
      for (int j = 0; j <= 3; j++) {
        if (!exits[i][j]) {
          G.push_back(make_pair(i, j));
        }
      }
    }
    flag = false;
    if (Joker == 1) {
      int len = G.size();
      for (int i = 0; i < len; i++) {
        int inx = P[0].first;
        int iny = P[0].second;
        card[inx][iny][0] = G[i].first;
        card[inx][iny][1] = G[i].second;
        solve();
        if (flag) break;
      }
    } else if (Joker == 2) {
      int len = G.size();
      for (int i = 0; i < len; i++) {
        int inx = P[0].first;
        int iny = P[0].second;
        card[inx][iny][0] = G[i].first;
        card[inx][iny][1] = G[i].second;
        for (int j = 0; j < len; j++) {
          if (j != i) {
            inx = P[1].first;
            iny = P[1].second;
            card[inx][iny][0] = G[j].first;
            card[inx][iny][1] = G[j].second;
            solve();
          }
          if (flag) break;
        }
        if (flag) break;
      }
    } else {
      solve();
    }
    if (flag) {
      if (!Joker) {
        printf("Solution exists.\n");
        printf("There are no jokers.\n");
        printf("Put the first square to (%d, %d).\n", res[0].first,
               res[0].second);
        printf("Put the second square to (%d, %d).\n", res[1].first,
               res[1].second);
      } else if (Joker == 1) {
        int jx = P[0].first;
        int jy = P[0].second;
        char rank_char = rerank(card[jx][jy][0]);
        char suit_char = resuit(card[jx][jy][1]);
        printf("Solution exists.\n");
        printf("Replace %s with %c%c.\n", Jo[0], rank_char, suit_char);
        printf("Put the first square to (%d, %d).\n", res[0].first,
               res[0].second);
        printf("Put the second square to (%d, %d).\n", res[1].first,
               res[1].second);
      } else if (Joker == 2) {
        printf("Solution exists.\n");
        int jx = P[0].first;
        int jy = P[0].second;
        int jx1 = P[1].first;
        int jy1 = P[1].second;
        char rank_char1 = rerank(card[jx][jy][0]);
        char suit_char1 = resuit(card[jx][jy][1]);
        char rank_char2 = rerank(card[jx1][jy1][0]);
        char suit_char2 = resuit(card[jx1][jy1][1]);
        if (Jo[0][1] == '1')
          printf("Replace %s with %c%c and %s with %c%c.\n", Jo[0], rank_char1,
                 suit_char1, Jo[1], rank_char2, suit_char2);
        else
          printf("Replace %s with %c%c and %s with %c%c.\n", Jo[1], rank_char2,
                 suit_char2, Jo[0], rank_char1, suit_char1);
        printf("Put the first square to (%d, %d).\n", res[0].first,
               res[0].second);
        printf("Put the second square to (%d, %d).\n", res[1].first,
               res[1].second);
      }
    } else {
      printf("No solution.\n");
    }
  }
  return 0;
}
