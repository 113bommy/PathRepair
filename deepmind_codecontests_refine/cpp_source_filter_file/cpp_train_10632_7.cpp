#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << "\b\b]\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int &i : A) cin >> i;
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    set<int, greater<int>> st;
    while (j < n and s[i] == s[j]) {
      st.insert(A[j]);
      j++;
    }
    int times = min(k, (int)st.size());
    auto it = st.begin();
    while (times--) {
      ans += *it;
      it++;
    }
    i = j - 1;
  }
  cout << ans;
  return 0;
}
