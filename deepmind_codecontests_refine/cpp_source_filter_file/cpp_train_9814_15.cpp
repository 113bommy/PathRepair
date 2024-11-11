#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    if (ret >= MOD) ret %= MOD;
    if (a >= MOD) a %= MOD;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) { return power(x, MOD - 2); }
const int N = 1e5 + 5;
int n;
long long A[N], ans;
vector<long long> v;
multiset<long long> st;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  st.insert(A[1]);
  for (int i = 2; i <= n; i++) {
    st.insert(A[i]);
    multiset<long long>::iterator it = st.end();
    --it;
    long long last = *it;
    if (A[i] >= last) continue;
    ans += abs(last - A[i]);
    st.erase(last);
    st.insert(A[i]);
  }
  cout << ans;
}
