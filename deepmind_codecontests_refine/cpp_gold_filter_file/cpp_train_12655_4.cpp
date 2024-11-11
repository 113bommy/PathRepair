#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> a, b;
int main() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    long long f;
    cin >> f;
    a.push_back(f);
    b.push_back(f);
  }
  long long ans = 0;
  for (long long i = 1; i <= n - 1; i++) {
    long long sum = a[i] + a[i - 1];
    if (sum < k) a[i] += k - sum, ans += k - sum;
  }
  if (n != 1)
    cout << ans << endl;
  else
    cout << 0 << endl;
  for (long long i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}
