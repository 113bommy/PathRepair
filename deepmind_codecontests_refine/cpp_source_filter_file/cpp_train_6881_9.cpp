#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MN = 1000010;
int N, K;
int A[MN];
vector<pair<int, int> > ord;
set<int> st;
int L[MN], R[MN];
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    ord.push_back(pair<int, int>(A[i], i));
  }
  sort(ord.begin(), ord.end());
  for (int i = 0; i < N; i++) {
    L[i] = -1;
    R[i] = N;
  }
  for (int i = (int)ord.size() - 1; i >= 0; i--) {
    int x = ord[i].second;
    auto it = st.upper_bound(x);
    if (it != st.end()) R[x] = *it;
    if (it != st.begin()) L[x] = *(--it);
    st.insert(x);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int l = i - L[i];
    int r = R[i] - i;
    int len = l + r - 1;
    if (l > r) swap(l, r);
    int tmp = 0;
    int x1 = (l - 1) / (K - 1);
    int x2 = (r - 1) / (K - 1) + 1;
    int x3 = (len - 1) / (K - 1);
    tmp += 1LL * x1 * (x1 + 1) / 2 % mod * K % mod;
    tmp %= mod;
    tmp += mod - 1LL * x1 * (x1 - 1) / 2 % mod;
    tmp %= mod;
    tmp += 1LL * (x2 - x1 - 1) * l % mod;
    tmp %= mod;
    if (x2 <= x3) {
      tmp += 1LL * (len + 1) * (x3 - x2 + 1) % mod;
      tmp %= mod;
      tmp += mod - (x3 - x2 + 1);
      tmp %= mod;
      tmp += 1LL * (x2 + x3) * (x3 - x2 + 1) / 2 % mod;
      tmp %= mod;
      tmp += mod - 1LL * (x2 + x3) * (x3 - x3 + 1) / 2 % mod * K % mod;
      tmp %= mod;
    }
    ans += 1LL * tmp * A[i] % mod;
    ans %= mod;
  }
  printf("%d", ans);
}
