#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int TN = 1;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  if (n == 1) {
    cout << 0;
    return;
  }
  sort((a).begin(), (a).end());
  if ((int)st.size() > 3) {
    cout << -1;
    return;
  }
  if ((int)st.size() == 1) {
    cout << 0;
    return;
  }
  vector<int> s;
  for (auto el : st) {
    s.push_back(el);
  }
  if ((int)s.size() == 2) {
    if ((s[1] - s[0]) % 2 == 0) {
      cout << (s[1] - s[0]) / 2;
      return;
    } else {
      cout << s[1] - s[0];
      return;
    }
  }
  if ((int)s.size() == 3) {
    if (s[2] - s[1] == s[1] - s[0]) {
      cout << s[2] - s[1];
      return;
    }
    cout << -1;
    return;
  }
}
int main() {
  auto start = chrono::steady_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (TN--) solve();
  auto finish = chrono::steady_clock::now();
  auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
  cerr << "Time: " << elapsed_ms.count() << " ms\n";
  return 0;
}
