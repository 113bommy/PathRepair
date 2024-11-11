#include <bits/stdc++.h>
const int md = 1e9 + 7;
const long long hs = 199;
const long double eps = 1e-9, pi = acos(-1);
using namespace std;
int n, a[100001], mx = -1, c = 1, p;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p, a[p - 1] = i;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      c++;
    else
      mx = max(mx, p), p = 1;
  }
  mx = max(mx, p);
  cout << n - mx << '\n';
}
