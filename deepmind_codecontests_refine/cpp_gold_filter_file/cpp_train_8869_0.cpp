#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
vector<int> s;
inline int count(int dim) {
  int sz = v.size();
  if (v[0].first > dim) return sz * dim;
  int lo = 0, hi = sz - 1;
  while (lo < hi) {
    int mi = lo + (hi - lo + 1) / 2;
    if (v[mi].first <= dim)
      lo = mi;
    else
      hi = mi - 1;
  }
  return s[lo] + (sz - lo - 1) * dim;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  for (auto x : mp) {
    v.push_back({x.second, x.first});
  }
  sort(v.begin(), v.end());
  s.resize(v.size());
  for (int i = 0; i < s.size(); i++) {
    s[i] = v[i].first;
    if (i) s[i] += s[i - 1];
  }
  int mxarea = 1;
  int mxdim = 1;
  for (int dim1 = 1; dim1 * dim1 <= n; dim1++) {
    int cnt = count(dim1);
    if (cnt / dim1 >= dim1) {
      int area = (cnt / dim1) * dim1;
      if (area > mxarea) {
        mxarea = area;
        mxdim = dim1;
      }
    }
  }
  reverse(v.begin(), v.end());
  cout << mxarea << '\n';
  int dim1 = mxdim;
  int dim2 = mxarea / dim1;
  vector<int> vec;
  for (auto x : v) {
    if (vec.size() == mxarea) break;
    for (int i = 0; i < dim1 && i < x.first && vec.size() < mxarea; i++) {
      vec.push_back(x.second);
    }
  }
  int a[dim1][dim2];
  for (int j = 0; j < dim2; j++) {
    for (int i = 0; i < dim1; i++) {
      a[i][j] = vec[j * dim1 + i];
    }
  }
  cout << dim1 << " " << dim2 << '\n';
  for (int i = 0; i < dim1; i++) {
    for (int j = 0; j < dim2; j++) {
      cout << a[i][(j + dim1 - i) % dim2] << " ";
    }
    cout << '\n';
  }
  return 0;
}
