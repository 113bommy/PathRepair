#include <bits/stdc++.h>
using namespace std;
long long n, a[2005], m, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  long long r = a[n - m];
  long long l = a[1 + k];
  cout << l - r;
}
