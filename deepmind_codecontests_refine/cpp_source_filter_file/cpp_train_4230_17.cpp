#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(const T &a) {
  return a * a;
}
template <typename T>
inline int nread(vector<T> &a) {
  int n;
  cin >> n;
  a.clear();
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return n;
}
vector<vector<int> > gr;
vector<int> key, fl, fr;
vector<double> res;
vector<pair<int, int> > obj;
int n, k, root;
void check(int v) {
  if (gr[v].size() == 0) {
    fl[v] = key[v];
    fr[v] = key[v];
  } else {
    if (key[gr[v][0]] > key[gr[v][1]]) {
      swap(gr[v][0], gr[v][1]);
    }
    check(gr[v][0]);
    check(gr[v][1]);
    fl[v] = fl[gr[v][0]];
    fr[v] = fr[gr[v][0]];
  }
}
void dfs(int v, int l = 0, int r = k - 1, long long int teksum = 0,
         int depth = 0) {
  if (l > r) return;
  if (gr[v].size() == 0) {
    for (int i = l; i <= r; i++) {
      res[obj[i].second] = teksum * 1. / depth;
    }
  } else {
    int ll = l, rr = r + 1;
    while (ll < rr) {
      int m = (ll + rr) / 2;
      if (obj[m].first < key[v])
        ll = m + 1;
      else
        rr = m;
    }
    dfs(gr[v][0], l, ll - 1, teksum + fl[gr[v][1]], depth + 1);
    dfs(gr[v][1], ll, r, teksum + fr[gr[v][0]], depth + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  gr.resize(n);
  key.resize(n);
  fl.assign(n, -1);
  fr = fl;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    if (x != -2) {
      gr[x].push_back(i);
    } else
      root = i;
    key[i] = y;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    obj.push_back(make_pair(x, i));
  }
  res.resize(k);
  sort(obj.begin(), obj.end());
  check(root);
  dfs(root);
  cout << fixed << setprecision(10);
  for (int i = 0; i < k; i++) {
    cout << res[i] << endl;
  }
}
