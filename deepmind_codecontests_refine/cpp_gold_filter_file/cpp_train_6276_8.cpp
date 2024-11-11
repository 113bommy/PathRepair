#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  set<pair<long long, long long> > st;
  for (int i = min(x1, x2); i <= max(x1, x2); i++) {
    st.insert(make_pair(i, y1));
  }
  for (int i = min(x1, x2); i <= max(x1, x2); i++) {
    st.insert(make_pair(i, y2));
  }
  for (int i = min(y1, y2); i <= max(y1, y2); i++) {
    st.insert(make_pair(x1, i));
  }
  for (int i = min(y1, y2); i <= max(y1, y2); i++) {
    st.insert(make_pair(x2, i));
  }
  int n;
  cin >> n;
  long long x[n], y[n], r[n];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
  set<pair<long long, long long> >::iterator it;
  int ctr = 0;
  for (it = st.begin(); it != st.end(); it++) {
    for (int i = 0; i < n; i++) {
      if (((it->first - x[i]) * (it->first - x[i]) +
           (it->second - y[i]) * (it->second - y[i])) <= r[i] * r[i]) {
        ctr++;
        break;
      }
    }
  }
  cout << st.size() - ctr << endl;
}
