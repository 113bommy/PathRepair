#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MOD = 1e9 + 7;
const long long INF = 1e15;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  int ans = 0;
  while (n--) {
    string s;
    cin >> s;
    set<int> st;
    for (int i = 0; i <= s.size() - 1; i++) st.insert(s[i] - '0');
    int l = 0;
    while (st.count(l)) l++;
    if (l == (k + 1)) ans++;
  }
  cout << ans;
  return 0;
}
