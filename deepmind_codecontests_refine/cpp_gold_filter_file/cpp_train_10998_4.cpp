#include <bits/stdc++.h>
using namespace std;
int n;
long long sum;
long long v[101000];
long long t[101000];
multiset<long long> s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n; i++) {
    long long ans = 0;
    s.insert(v[i] + sum);
    sum += t[i];
    while (!s.empty() && *s.begin() <= sum) {
      ans += t[i] - (sum - *s.begin());
      s.erase(s.begin());
    }
    ans += t[i] * (long long)s.size();
    cout << ans << ' ';
  }
}
