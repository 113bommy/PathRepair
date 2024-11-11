#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000000000000001;
inline long long add(long long a, long long b) {
  if ((a += b) >= MAX) a = MAX;
  return a;
}
class SAM {
 public:
  int ch[200010][4], len[200010], fail[200010], d[200010][4];
  int ptr, lst;
  SAM() { ptr = lst = 1; }
  void append(int c) {
    int cur = ++ptr;
    len[cur] = len[lst] + 1;
    int p = lst;
    for (; p && !ch[p][c]; p = fail[p]) ch[p][c] = cur;
    if (!p)
      fail[cur] = 1;
    else {
      int q = ch[p][c];
      if (len[q] == len[p] + 1)
        fail[cur] = q;
      else {
        int cl = ++ptr;
        memcpy(ch[cl], ch[q], sizeof(ch[cl]));
        len[cl] = len[p] + 1;
        fail[cl] = fail[q];
        for (; p && ch[p][c] == q; p = fail[p]) ch[p][c] = cl;
        fail[cur] = fail[q] = cl;
      }
    }
    lst = cur;
  }
  int buc[200010], topo[200010];
  long long st[4][4][60];
  void build() {
    int mx = 0;
    for (int i = 1; i <= ptr; i++) buc[len[i]]++, mx = max(mx, len[i]);
    for (int i = 1; i <= mx; i++) buc[i] += buc[i - 1];
    for (int i = ptr; i >= 1; i--) topo[buc[len[i]]--] = i;
    memset(d, 0x3f, sizeof(d));
    for (int i = ptr; i >= 1; i--) {
      for (int j = 0; j < 4; j++) {
        if (!ch[topo[i]][j]) {
          d[topo[i]][j] = 1;
        } else {
          for (int k = 0; k < 4; k++)
            d[topo[i]][k] = min(d[topo[i]][k], d[ch[topo[i]][j]][k] + 1);
        }
      }
    }
    memset(st, 0x3f, sizeof(st));
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        st[i][j][0] = d[ch[1][i]][j];
      }
    }
    for (int i = 1; i < 60; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          for (int l = 0; l < 4; l++) {
            st[j][l][i] =
                min(st[j][l][i], add(st[j][k][i - 1], st[k][l][i - 1]));
          }
        }
      }
    }
  }
} sam;
long long n;
char t[100010];
int main() {
  scanf("%lld%s", &n, t + 1);
  int len = strlen(t + 1);
  for (int i = 1; i <= len; i++) sam.append(t[i] - 'A');
  sam.build();
  long long ans = 0;
  long long curd[4] = {0, 0, 0, 0};
  for (int T = 59; T >= 0; T--) {
    long long td[4];
    memset(td, 0x3f, sizeof(td));
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        td[j] = min(td[j], add(curd[i], sam.st[i][j][T]));
      }
    }
    if (*min_element(td, td + 4) < n) {
      ans += (1ll << T);
      memcpy(curd, td, sizeof(curd));
    }
  }
  printf("%lld\n", ans + 1);
  return 0;
}
