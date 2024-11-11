#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
set<pair<int, int> > st;
int n, k, q, t[N];
int main() {
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) cin >> t[i];
  while (q--) {
    int type, id;
    cin >> type >> id;
    id--;
    if (type == 1) {
      if (st.size() < k)
        st.insert(make_pair(t[id], id));
      else {
        st.insert(make_pair(t[id], id));
        st.erase(st.begin());
      }
    } else {
      if (st.count(make_pair(t[id], id)))
        cout << "YES" << endl;
      else
        cout << "NO";
    }
  }
  return 0;
}
