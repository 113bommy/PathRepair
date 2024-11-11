#include <bits/stdc++.h>
using namespace std;
set<long long> st;
const long long mx = 1e18;
std::vector<long long> v;
void pre() {
  for (long long i = 2; i <= 1000006; i++) {
    for (long long j = i * i * i; j <= mx; j *= i) {
      long long g = sqrt(j);
      if (g * g != j) {
        st.insert(j);
      }
      if (j > mx / i) break;
    }
  }
  v.assign(st.begin(), st.end());
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  long long T;
  cin >> T;
  pre();
  while (T--) {
    long long n;
    cin >> n;
    long long ans = lower_bound(v.begin(), v.end(), n) -
                    lower_bound(v.begin(), v.end(), 2 - 1);
    ans += sqrt(n) - sqrt(2 - 1);
    ans = n - 2 + 1 - ans;
    cout << ans << "\n";
  }
  return 0;
}
