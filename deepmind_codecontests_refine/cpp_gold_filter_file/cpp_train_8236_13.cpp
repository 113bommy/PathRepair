#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = 998244353;
const int inf = (1 << 30) - 1;
int n, A;
long long a[maxn];
long long c[maxn];
long long L[maxn];
long long R[maxn];
long long sum[maxn];
long long suml[maxn];
long long sqr(long long x) { return x * x; }
void solve() {
  cin >> n >> A;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
    c[i] = A - c[i];
    ans = max(ans, c[i]);
  }
  vector<int> st;
  for (int i = 1; i < n; i++) {
    long long cur_sum = 0;
    long long max_sum = 0;
    while (st.size() > 0 &&
           sqr(a[st.back()] - a[st.back() - 1]) <= sqr(a[i] - a[i - 1])) {
      max_sum = max(suml[st.size()] + cur_sum, max_sum);
      cur_sum += sum[st.size()];
      st.pop_back();
    }
    st.emplace_back(i);
    sum[st.size()] = cur_sum + c[i - 1];
    suml[st.size()] = max(max_sum + c[i - 1], c[i - 1]);
    L[i] = max_sum + c[i - 1];
  }
  st.clear();
  for (int i = n - 1; i > 0; i--) {
    long long cur_sum = 0;
    long long max_sum = 0;
    while (st.size() > 0 &&
           sqr(a[st.back()] - a[st.back() - 1]) <= sqr(a[i] - a[i - 1])) {
      max_sum = max(suml[st.size()] + cur_sum, max_sum);
      cur_sum += sum[st.size()];
      st.pop_back();
    }
    st.emplace_back(i);
    sum[st.size()] = cur_sum + c[i];
    suml[st.size()] = max(max_sum + c[i], c[i]);
    R[i] = max_sum + c[i];
  }
  for (int i = 1; i < n; i++) {
    ans = max(ans, L[i] + R[i] - sqr(a[i] - a[i - 1]));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
