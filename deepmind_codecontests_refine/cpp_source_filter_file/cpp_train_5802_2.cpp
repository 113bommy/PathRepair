#include <bits/stdc++.h>
using namespace std;
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
map<int, int> have;
int a[100005];
int p[100005];
int psize[100005];
vector<pair<int, int> > v;
void delsize(int sz) {
  have[sz]--;
  if (have[sz] == 0) {
    have.erase(sz);
  }
}
int getP(int v) {
  if (!p[v]) return 0;
  if (p[v] == v)
    return v;
  else
    return p[v] = getP(p[v]);
}
void unite(int a, int b) {
  a = getP(a);
  b = getP(b);
  if (psize[a] > psize[b]) {
    p[b] = a;
    psize[a] += psize[b];
  } else {
    p[a] = b;
    psize[b] += psize[a];
  }
}
void add(int pos) {
  p[pos] = pos;
  psize[pos] = 1;
  have[1]++;
  int x = getP(pos + 1);
  if (x) {
    delsize(psize[x]);
    delsize(1);
    unite(x, pos);
    have[psize[getP(pos)]]++;
  }
  x = getP(pos - 1);
  int cur = getP(pos);
  if (x) {
    delsize(psize[x]);
    delsize(psize[cur]);
    unite(pos, x);
    have[psize[getP(pos)]]++;
  }
}
int main() {
  file();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  sort(v.begin(), v.end());
  int loccnt = 0;
  int ans = 2e9;
  for (int i = 0; i < v.size() - 1; i++) {
    int pos = v[i].second;
    add(pos);
    if (have.size() == 1) {
      if (loccnt < have.begin()->second) {
        loccnt = have.begin()->second;
        ans = v[i].first + 1;
      }
    }
  }
  cout << ans;
  return 0;
}
