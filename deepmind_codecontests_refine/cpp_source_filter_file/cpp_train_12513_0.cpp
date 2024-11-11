#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int sum = 0;
  vector<long long> s(n, 0);
  for (int i = 0; i < n; i++) {
    s[i % m] += v[i];
    sum += s[i % m];
    cout << sum << " ";
  }
  return 0;
}
