#include <bits/stdc++.h>
using namespace std;
vector<int> vv, v[5005];
set<int> st;
map<int, int> mp, mk;
int ar[5005];
bool comp(int a, int b) { return mp[a] < mp[b]; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) v[i].clear();
    st.clear();
    mp.clear();
    vv.clear();
    mk.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ar[i] = x;
      st.insert(x);
    }
    int ii = 0;
    for (int x : st) mk[x] = ++ii;
    st.clear();
    for (int i = 0; i < n; i++) {
      int x;
      x = mk[ar[i]];
      st.insert(x);
      v[x].push_back(i);
      mp[x]++;
    }
    for (int x : st) vv.push_back(x);
    sort(vv.begin(), vv.end(), comp);
    if (vv.size() >= 2) {
      cout << "YES" << endl;
      int p = vv[0];
      int s = v[p][0], ex;
      for (int i = 1; i < vv.size(); i++) {
        int x = vv[i];
        for (int k : v[x]) {
          cout << s + 1 << " " << k + 1 << endl;
          ex = k;
        }
      }
      for (int i = 1; i < v[p].size(); i++)
        cout << ex + 1 << " " << v[p][i] + 1 << endl;
    } else
      cout << "NO" << endl;
  }
}
