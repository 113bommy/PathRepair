#include <bits/stdc++.h>
using namespace std;
int const N = 2e3 + 10;
int n, aa, b, a[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> aa >> b;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << a[b] - a[aa];
}
