#include <bits/stdc++.h>
const long long mod = 1000000007;
const long long oo = 1E18 + 3;
const int MAXN = 1E5 + 3;
using namespace std;
vector<int> b;
int a[MAXN], f[MAXN], n, B;
int main() {
  cin >> n >> B;
  int tmp = 0;
  for (int i = (1), _b = (n); i <= _b; i = i + 1) cin >> a[i];
  for (int i = (1), _b = (n - 1); i <= _b; i = i + 1) {
    if (a[i] % 2 == 1)
      tmp -= 1;
    else
      tmp += 1;
    f[i] = tmp;
    if (f[i] == 0) b.push_back(abs(a[i + 1] - a[i]));
  }
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0, _n = (b.size()); i < _n; i = i + 1) {
    B -= b[i];
    if (B >= 0)
      ans++;
    else
      break;
  }
  cout << ans;
  return 0;
}
