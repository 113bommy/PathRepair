#include <bits/stdc++.h>
using namespace std;
const int mxn = 601;
int n, m;
int a[mxn], d[mxn], p[mxn], first[mxn], vis[mxn];
vector<int> v[mxn];
stack<int> stk;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < 3 * n; i++) {
    int x;
    cin >> x;
    a[--x] = 1;
  }
  first[m] = -1;
  stk.push(m++);
  for (int i = 0; i < 6 * n; i++) {
    int x = stk.top();
    if (first[x] == a[i]) {
      v[x].push_back(i + 1);
      if (v[x].size() == 3) stk.pop();
    } else {
      d[p[m] = x]++, first[m] = a[i];
      v[m].push_back(i + 1);
      stk.push(m++);
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    int x = -1;
    for (int i = 1; i <= 2 * n && (!~x || !p[x]); i++) {
      if (!vis[i] && first[i] == !(i & 1) && !d[i]) x = i;
    }
    vis[x] = 1, d[p[x]]--;
    cout << v[x][0] << " " << v[x][1] << " " << v[x][2] << '\n';
  }
  return 0;
}
