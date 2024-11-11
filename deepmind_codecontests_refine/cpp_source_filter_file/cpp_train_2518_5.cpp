#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  int f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 - '0' + ch;
    ch = getchar();
  }
  x *= f;
}
const int maxn = 4000 + 5;
int T;
int n;
char a[maxn], b[maxn];
int cnt[2][4];
vector<int> an;
inline int idx(char a, char b) { return (a - '0') << 1 | (b - '0'); }
void sol() {
  for (int i = 0; i < n; i += 2) {
    for (int j = i + 1; j <= n; j += 2) {
      if (a[j] == b[n - i] && a[j + 1] == b[n - i - 1]) {
        if (j != 1) {
          an.push_back(j - 1);
          reverse(a + 1, a + j);
        }
        an.push_back(j + 1);
        reverse(a + 1, a + j + 2);
        break;
      }
    }
  }
}
int main() {
  read(T);
  for (int kase = 1; kase <= T; ++kase) {
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    n = strlen(a + 1);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i += 2) {
      ++cnt[0][idx(a[i], a[i + 1])];
      ++cnt[1][idx(b[i], b[i + 1])];
    }
    if (cnt[0][0] != cnt[1][0] || cnt[0][3] != cnt[1][3]) {
      puts("-1");
      continue;
    }
    int x = cnt[0][1] - cnt[0][2];
    int y = cnt[1][1] - cnt[1][2];
    an.clear();
    if (x + y == 0)
      sol();
    else {
      if (abs(x) >= abs(y)) {
        int d = (x + y) / 2, k = -1;
        for (int i = 1; i <= n; i += 2) {
          int t = idx(a[i], a[i + 1]);
          if (t == 1) ++d;
          if (t == 2) --d;
          if (d == 0) {
            k = i + 1;
            break;
          }
        }
        an.push_back(k);
        reverse(a + 1, a + k + 1);
        sol();
      } else {
        int d = (x + y) / 2, k = -1;
        for (int i = 1; i <= n; i += 2) {
          int t = idx(b[i], b[i + 1]);
          if (t == 1) --d;
          if (t == 2) ++d;
          if (d == 0) {
            k = i + 1;
            break;
          }
        }
        reverse(b + 1, b + k + 1);
        sol();
        an.push_back(k);
      }
    }
    printf("%d\n", (int)an.size());
    for (int i = 0; i < an.size(); ++i) {
      if (i) printf(" ");
      printf("%d", an[i]);
    }
    printf("\n");
  }
  return 0;
}
