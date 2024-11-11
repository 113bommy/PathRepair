#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T rd() {
  bool f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 0;
  T x = 0;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return f ? x : -x;
}
vector<int> solve(vector<int> a) {
  a.erase(unique(a.begin(), a.end()), a.end());
  for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
    if (*it == 0) {
      a.erase(it);
      break;
    }
  vector<int> res;
  if (a.empty()) return res;
  if (a.size() == 1 && abs(a[0]) == 1) return res.push_back(a[0]), res;
  bool cnt1 = false;
  for (int i = (0), _ = (a.size()); i < _; ++i)
    if (a[i] & 1) {
      cnt1 = true;
      break;
    }
  if (!cnt1) {
    for (int i = (0), _ = (a.size()); i < _; ++i) a[i] /= 2;
    res = solve(a);
    for (int i = (0), _ = (res.size()); i < _; ++i) res[i] *= 2;
    return res;
  } else {
    vector<int> b;
    b.resize(a.size());
    for (int i = (0), _ = (a.size()); i < _; ++i)
      b[i] = (a[i] + (a[i] & 1)) / 2;
    res = solve(b);
    for (int i = (0), _ = (a.size()); i < _; ++i)
      b[i] = (a[i] - (a[i] & 1)) / 2;
    vector<int> _res = solve(b);
    if (res.size() < _res.size()) {
      for (int i = (0), _ = (res.size()); i < _; ++i) res[i] *= 2;
      res.push_back(-1);
      return res;
    } else {
      for (int i = (0), _ = (_res.size()); i < _; ++i) _res[i] *= 2;
      _res.push_back(1);
      return _res;
    }
  }
}
int main() {
  int n = rd<int>();
  vector<int> a;
  for (int i = (1), _ = (n); i <= _; ++i) a.push_back(rd<int>());
  sort(a.begin(), a.end());
  vector<int> res = solve(a);
  sort(res.begin(), res.end());
  printf("%d\n", (int)res.size());
  for (int i = (0), _ = (res.size()); i < _; ++i)
    printf("%d%c", res[i], " \n"[i == (int)res.size() - 1]);
  return 0;
}
