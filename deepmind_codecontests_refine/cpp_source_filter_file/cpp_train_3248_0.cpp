#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;
using ll = long long;
const int N = 1e6 + 2;
int n, cnt, f[N], vis[N];
int qt, q[N];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  if (n & 1) return cout << "-1\n", 0;
  v.push_back(0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a > 0) {
      if (f[a] || vis[a]) return cout << "-1\n", 0;
      ++f[a], ++cnt, vis[a] = 1, q[++qt] = a;
    } else {
      a = -a;
      if (!f[a]) return cout << "-1\n", 0;
      --f[a], --cnt;
      if (!cnt) {
        v.push_back(i + 1);
        while (qt--) vis[q[qt]] = 0;
      }
    }
  }
  if (cnt) return cout << "-1\n", 0;
  cout << v.size() - 1 << '\n';
  for (int i = 1; i < v.size(); ++i)
    cout << v[i] - v[i - 1] << " \n"[i + 1 == v.size()];
}
