#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while ('0' > ch || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
const int maxn = 1e5 + 10;
int a[1000];
int main() {
  int s[1000];
  int n, k, temp;
  cin >> n >> k;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &temp);
    if (cnt < k) {
      int j;
      for (j = 0; j < cnt; ++j)
        if (s[j] == temp) break;
      if (j == cnt) s[cnt++] = temp;
    } else {
      int flag = false;
      for (int j = 0; j < cnt; ++j)
        if (s[j] == temp) {
          flag = true;
          break;
        }
      if (flag) continue;
      for (int j = 0; j < cnt - 1; ++j) s[j] = s[j + 1];
      s[cnt - 1] = temp;
    }
  }
  printf("%d\n", cnt);
  for (int i = cnt - 1; i >= 0; --i) printf("%d ", s[i]);
  return 0;
}
