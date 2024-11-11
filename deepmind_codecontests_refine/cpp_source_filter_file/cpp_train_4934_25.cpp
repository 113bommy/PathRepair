#include <bits/stdc++.h>
const int MAX_LEN = 1010;
using namespace std;
template <typename U, typename V>
string to_string(pair<U, V>);
string to_string(const string& e_) { return "\"" + e_ + "\""; }
string to_string(char e_) { return "\'" + string(1, e_) + "\'"; }
string to_string(bool e_) { return e_ ? "true" : "false"; }
template <typename T>
string to_string(T e_) {
  string s_ = "[ ";
  for (const auto& x_ : e_) s_ += to_string(x_) + " ";
  return s_ + "]";
}
template <typename U, typename V>
string to_string(pair<U, V> e_) {
  return "(" + to_string(e_.first) + ", " + to_string(e_.second) + ")";
}
void dbg_str() { ; }
template <typename U, typename... V>
void dbg_str(U u, V... v) {
  ;
  dbg_str(v...);
}
int cd, cm, cy;
int solve(int d, int m, int y) {
  if (y < 1 || y > 99) return 0;
  if (m < 1 || m > 12) return 0;
  if (m == 4 || m == 6 || m == 9 || m == 11) {
    if (d > 30) return 0;
  } else if (m == 2) {
    if (y % 4 && d > 29) return 0;
    if (!(y % 4) && d > 28) return 0;
  } else if (d > 31)
    return 0;
  if (cy - y > 18) return 1;
  if (cy - y == 18 && cm - m > 0) return 1;
  if (cy - y == 18 && cm - m == 0 && cd - d >= 0) return 1;
  return 0;
}
int a[3];
int main() {
  scanf("%d.%d.%d", &cd, &cm, &cy);
  scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
  bool poss = false;
  do {
    if (solve(a[0], a[1], a[2])) poss = true;
  } while (next_permutation(a, a + 3));
  printf("%s\n", poss ? "YES" : "NO");
}
