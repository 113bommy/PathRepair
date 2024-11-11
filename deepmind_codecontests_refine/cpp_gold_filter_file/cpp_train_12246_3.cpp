#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const long long mod = 998244353;
const int N = 5e5 + 5;
int a[N], n, k, mnid, mn2id, ind[N], ri[N];
stack<int> st;
bool cmp(const int &i, const int &j) {
  return (a[i] < a[j]) || (a[i] == a[j] && i < j);
}
void no() {
  cout << "NO" << '\n';
  exit(0);
}
void yes() {
  cout << "YES" << '\n';
  exit(0);
}
void solve() {
  cin >> n >> k;
  for (int i = (int)0; i != (int)n; i = i + 1) cin >> a[i];
  ;
  iota(ind, ind + n, 0);
  sort(ind, ind + n, cmp);
  mnid = mn2id = n;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] > a[i]) {
      ri[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    ri[st.top()] = n;
    st.pop();
  }
  for (int i = 0; i < n; i++) {
    if (ind[i] + k < mn2id) return no();
    if (ind[i] + k < mnid) {
      for (int j = 0; j < ind[i]; j++) {
        if (ri[j] - j > k) return no();
      }
      return yes();
    }
    mn2id = min(mn2id, mnid - k);
    mnid = min(mnid, ind[i]);
  }
  return yes();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
