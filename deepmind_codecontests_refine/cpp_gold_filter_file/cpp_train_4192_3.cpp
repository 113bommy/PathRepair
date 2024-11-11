#include <bits/stdc++.h>
using namespace std;
vector<long long int> divisor;
void getDivisors(long long int n) {
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        divisor.push_back(i);
      else {
        divisor.push_back(i);
        divisor.push_back(n / i);
      }
    }
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n], w[k];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (long long int j = 0; j < k; j++) cin >> w[j];
    long long int ans = 0;
    sort(a, a + n, greater<long long int>());
    sort(w, w + k);
    vector<long long int> v;
    for (long long int i = 0; i < k; i++) {
      ans = ans + a[i];
      w[i] = w[i] - 1;
      if (w[i] == 0) {
        ans = ans + a[i];
      } else {
        v.push_back(w[i]);
      }
    }
    long long int j = 0;
    sort(v.begin(), v.end(), greater<long long int>());
    for (long long int i = 0; i < v.size(); i = i + 1) {
      ans = ans + a[n - j - 1];
      j += v[i];
    }
    cout << ans << endl;
  }
}
