#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * (b / (gcd(a, b))); }
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline long long toLL(string s) {
  long long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
using namespace std;
queue<int> left_window;
queue<int> left_occ;
queue<int> right_window;
queue<int> right_occ;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= 2 * n; i++) {
    if (i % 2 == 1)
      left_window.push(i);
    else
      right_window.push(i);
  }
  int c = 2 * n + 1;
  for (int i = c; i <= m; i++) {
    if (i % 2 == 1)
      left_occ.push(i);
    else
      right_occ.push(i);
  }
  while (1) {
    int sz_lw = ((int)((left_window).size()));
    int sz_rw = ((int)((right_window).size()));
    int sz_lc = ((int)((left_occ).size()));
    int sz_rc = ((int)((right_occ).size()));
    if (sz_lw == 0 && sz_rw == 0 && sz_lc == 0 && sz_rc == 0) break;
    if (sz_lc != 0) {
      cout << left_occ.front() << " ";
      left_occ.pop();
    }
    if (sz_lw != 0) {
      cout << left_window.front() << " ";
      left_window.pop();
    }
    if (sz_rc != 0) {
      cout << right_occ.front() << " ";
      right_occ.pop();
    }
    if (sz_rw != 0) {
      cout << right_window.front() << " ";
      right_window.pop();
    }
  }
}
