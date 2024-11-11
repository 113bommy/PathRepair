#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast;
  long long int n, m, r;
  cin >> n >> m >> r;
  vector<long long int> v1(n);
  vector<long long int> v2(m);
  for (auto &i : v1) cin >> i;
  for (auto &i : v2) cin >> i;
  long long int k = *min_element(v1.begin(), v1.end());
  long long int l = *max_element(v2.begin(), v2.end());
  long long int ans = r;
  ans -= (r / k) * k;
  ans += (r / k) * l;
  cout << max(ans, r);
}
