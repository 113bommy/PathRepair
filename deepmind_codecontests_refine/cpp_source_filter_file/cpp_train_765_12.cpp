#include <bits/stdc++.h>
using namespace std;
inline int to_int(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string to_str(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int INF = (int)1e9;
const int DR[] = {0, 1, 0, -1};
const int DC[] = {1, 0, -1, 0};
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline double dis(T x1, T x2, T y1, T y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
template <class T>
inline bool is_inner(T x, T a, T b) {
  return a <= x && x <= b;
}
bool mark[27][27][27];
const int kMaxN = 35;
int N;
std::string titles[kMaxN];
void solve() {
  memset(mark, false, sizeof(mark));
  std::cin >> N;
  for (int i = (int)(0); i < (int)(N); ++i) std::cin >> titles[i];
  for (int i = (int)(0); i < (int)(N); ++i) {
    for (int j = (int)(0); j < (int)(titles[i].size()); ++j) {
      mark[0][0][(titles[i][j]) - 'a' + 1] = true;
      if (j + 1 < (int)titles[i].size()) {
        mark[0][(titles[i][j]) - 'a' + 1][(titles[i][j + 1]) - 'a' + 1] = true;
      }
      if (j + 2 < (int)titles[i].size()) {
        mark[(titles[i][j]) - 'a' + 1][(titles[i][j + 1]) - 'a' + 1]
            [(titles[i][j + 2]) - 'a' + 1] = true;
      }
    }
  }
  for (int i = (int)(0); i < (int)(26); ++i) {
    for (int j = (int)(0); j < (int)(26); ++j) {
      if (i != 0 && j == 0) continue;
      for (int k = (int)(1); k < (int)(26); ++k) {
        if (!mark[i][j][k]) {
          if (i != 0) std::cout << (char)('a' + i - 1);
          if (j != 0) std::cout << (char)('a' + j - 1);
          std::cout << (char)('a' + k - 1) << std::endl;
          return;
        }
      }
    }
  }
}
int main(int argc, char *argv[]) {
  solve();
  return 0;
}
