#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 200010;
int n, T, x[maxn], y[maxn], m, k, c[300010], d[300010], cnt, pos;
long long ans, a, b;
char s[110];
int main() {
  scanf("%d", &T);
  while (T--) {
    memset(s, 0, sizeof(s));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      s[i * 2] = '(';
      s[i * 2 + 1] = ')';
    }
    cout << s << '\n';
    s[1] = '(';
    for (int i = 1; i < n; i++) {
      s[i * 2] = ')';
      cout << s << '\n';
      s[i * 2] = '(';
    }
  }
}
