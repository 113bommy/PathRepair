#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ans = 0, lev = 0;
  string s;
  cin >> n >> k;
  cin >> s;
  queue<string> q;
  set<string> st;
  q.push(s);
  st.insert(s);
  while (!q.empty() && (st.size()) < k) {
    string sr = q.front();
    q.pop();
    for (int i = 0; i < (sr.size()); i++) {
      string sr1 = sr;
      sr1.erase(i, 1);
      if (!st.count(sr1) && st.size() < k) {
        q.push(sr1);
        st.insert(sr1);
        ans += (n - sr.size());
      }
    }
  }
  if (int(st.size()) < k) {
    cout << "-1";
    return 0;
  }
  cout << ans;
}
