#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f;
using namespace std;
const int maxn = 2e5 + 5;
int t, n;
long long sum[maxn];
vector<int> a[maxn];
struct node {
  long long su;
  int pos, id;
  bool operator<(const node b) const { return su < b.su; }
};
set<node> st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int j = 1; j <= t; j++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[j].push_back(x);
      sum[j] += x;
    }
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < a[j].size(); i++) {
      node tmp, tt;
      tmp.id = j;
      tmp.pos = i + 1;
      tmp.su = sum[j] - a[j][i];
      if (st.empty()) {
        st.insert(tmp);
        continue;
      }
      set<node>::iterator it = st.lower_bound(tmp);
      if (it != st.end())
        tt = *it;
      else {
        st.insert(tmp);
        continue;
      }
      if (tmp.su == tt.su) {
        if (tmp.id != tt.id) {
          cout << "YES" << endl;
          cout << tmp.id << " " << tmp.pos << endl;
          cout << tt.id << " " << tt.pos << endl;
          return 0;
        }
      } else
        st.insert(tmp);
    }
  }
  cout << "NO" << endl;
  return 0;
}
