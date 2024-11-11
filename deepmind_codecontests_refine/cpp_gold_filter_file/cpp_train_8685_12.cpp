#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
inline int spr(int a) { return a * a; }
vector<int> solve(int n) {
  vector<int> res;
  if (n == 1)
    res.push_back(1);
  else if (n == 2)
    res.push_back(3), res.push_back(4);
  else if (n & 1) {
    for (int i = 0; i < (n - 2); ++i) res.push_back(1);
    res.push_back(2);
    res.push_back((n + 3) / 2 - 1);
  } else {
    for (int i = 0; i < (n - 1); ++i) res.push_back(1);
    res.push_back((n / 2) - 1);
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> row = solve(n), col = solve(m);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j)
      printf("%d%c", row[i] * col[j], j == m - 1 ? '\n' : ' ');
  return 0;
}
