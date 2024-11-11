#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, a, b, k, f;
map<string, int> id;
map<pair<int, int>, int> m;
vector<pair<int, int> > edg;
int go() {
  int at = -1, res = 0;
  for (auto it : edg) {
    pair<int, int> route =
        pair<int, int>(min(it.first, it.second), max(it.first, it.second));
    if (it.first == at) {
      res += b;
      m[route] += b;
    } else {
      res += a;
      m[route] += a;
    }
    at = it.second;
  }
  vector<int> v;
  for (auto it : m) v.push_back(it.second);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < k and i < (int)v.size() and v[i] > f; i++) {
    res -= v[i];
    res += f;
  }
  return res;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n >> a >> b >> k >> f;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    if (!id.count(a)) id[a] = id.size();
    if (!id.count(b)) id[b] = id.size();
    edg.push_back(pair<int, int>(id[a], id[b]));
  }
  cout << go() << endl;
  return 0;
}
