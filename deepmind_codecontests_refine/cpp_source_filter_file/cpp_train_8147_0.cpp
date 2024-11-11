#include <bits/stdc++.h>
using namespace std;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int mi = 1000000007;
map<pair<int, int>, int> mp;
int minima[2000000];
int f(int a, int b) {
  if (mp.find(make_pair(a, b)) != mp.end()) {
    return mp[make_pair(a, b)];
  }
  cout << "? " << a << " " << b << endl;
  int s;
  cin >> s;
  chmin(mi, s);
  return mp[make_pair(a, b)] = s;
}
void SMAWK(vector<int> js, int ib, int ie, int id) {
  if (ib > ie) return;
  vector<int> js2;
  for (int q = 0, i = ib; q < js.size(); ++q) {
    while (!js2.empty() && f(i, js2.back()) >= f(i, js[q])) {
      js2.pop_back();
      i -= id;
    }
    if (js2.size() != (ie - ib) / id) {
      js2.push_back(js[q]);
      i += id;
    }
  }
  SMAWK(js2, ib + id, ie, id * 2);
  for (int i = ib, q = 0; i <= ie; i += id * 2) {
    int jt = (i + id <= ie ? minima[i + id] : js.back());
    int fm = 99999999, fq;
    for (; q < js.size(); ++q) {
      if (fm > (fq = f(i, js[q]))) {
        fm = fq;
        minima[i] = js[q];
      }
      if (js[q] == jt) break;
    }
  }
}
void rowMinimaTM(int ib, int ie, int jb, int je) {
  vector<int> js;
  for (int j = jb; j <= je; ++j) js.push_back(j);
  SMAWK(js, ib, ie, 1);
}
int main() {
  int n, m;
  cin >> n >> m;
  rowMinimaTM(1, n, 1, m);
  cout << "! " << mi << endl;
  return 0;
}
