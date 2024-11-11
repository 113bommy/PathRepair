#include <bits/stdc++.h>
using namespace std;
long long int n, k, ke;
long long int a[100009], b[100009];
vector<long long int> x;
long long int ans = 0;
int main() {
  cin >> n >> k;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (long long int i = 0; i < n; i++) {
    ans += b[i];
    x.push_back(a[i] - b[i]);
    if (a[i] - b[i] < 0) ke++;
  }
  sort(x.begin(), x.end());
  k = max(k, ke);
  for (long long int i = 0; i < k; i++) {
    ans += x[i];
  }
  cout << ans;
}
