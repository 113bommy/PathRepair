#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, k, res = 0;
  scanf("%d %d\n", &n, &k);
  getline(cin, s);
  set<string> st;
  queue<string> dq;
  st.insert(s);
  dq.push(s);
  while (dq.size() > 0) {
    string e = dq.front();
    dq.pop();
    for (int i = 0; i < e.size(); i++) {
      string ne = e;
      ne.erase(i, 1);
      if (st.count(ne) == 0 && st.size() + 1 <= k) {
        st.insert(ne);
        dq.push(ne);
        res += n - ne.size();
      }
    }
  }
  if (res >= k)
    cout << res;
  else
    cout << -1;
}
