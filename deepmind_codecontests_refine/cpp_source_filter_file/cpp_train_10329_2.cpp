#include <bits/stdc++.h>
using namespace std;
const int inf = 0xfffffff;
int ma = -1, mi = inf;
int cmp(int a, int b) { return a > b; }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
string a[1000], b[1000];
int fa[250005];
int main() {
  long long n, t, m, p, d, w;
  string s;
  ios::sync_with_stdio(false);
  cin.tie(0);
  fa[0] = 1;
  while (cin >> n >> m) {
    long long res = 0;
    for (int i = 1; i <= n; i++) fa[i] = (fa[i - 1] % m * i % m);
    for (int i = 1; i <= n; i++) {
      res += (((n - i + 1) % m * (n - i + 1) % m) % m *
              ((fa[i] % m * fa[n - i] % m) % m)) %
             m;
    }
    cout << res << endl;
  }
  return 0;
}
