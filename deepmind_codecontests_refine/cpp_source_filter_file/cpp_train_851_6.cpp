#include <bits/stdc++.h>
using namespace std;
long long int pow2(long long int a, long long int n, long long int p) {
  if (a == 0) return 0;
  if (n == 0) return 1;
  if (n % 2 == 0)
    return (pow2(((a % p) * (a % p)) % p, n / 2, p) % p);
  else
    return ((pow2(((a % p) * (a % p)) % p, n / 2, p) % p) * (a % p)) % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    long long int n;
    cin >> n;
    pair<long long int, long long int> a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a, a + n);
    vector<long long int> v(n + 1, 1e9);
    v[0] = 0;
    long long int i, j, x;
    long long int vst[n + 1];
    memset(vst, -1, sizeof(vst));
    for (i = 0; i < n; i++) {
      for (j = 3; j <= 5 && i + j <= n; j++) {
        long long int df = a[i + j - 1].first - a[i].first;
        if (v[i + j] > v[i] + df) {
          v[i + j] = v[i] + df;
          vst[i + j] = i;
        }
      }
    }
    long long int ans[n];
    long long int n1 = n;
    long long int ct = 0;
    while (n1) {
      for (i = n1 - 1; i >= vst[n1]; i--) ans[a[i].second] = ct;
      ct++;
      n1 = vst[n1];
    }
    cout << v[n] << " " << ct << "\n";
    for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
