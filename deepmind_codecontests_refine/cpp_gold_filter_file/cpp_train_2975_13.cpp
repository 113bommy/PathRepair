#include <bits/stdc++.h>
using namespace std;
template <typename Iter>
ostream& _out(ostream& s, Iter a, Iter b) {
  for (auto it = a; it != b; it++) s << (it == a ? "" : " ") << *it;
  return s;
}
template <typename A, typename B>
ostream& operator<<(ostream& s, pair<A, B>& p) {
  return s << "(" << p.first << " , " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  return _out(s, v.begin(), v.end());
}
inline long long rit() {
  int key = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') key = -1;
    c = getchar();
  }
  long long x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * key;
}
int __ = 1;
void init() {}
void read() {}
void solve() {}
int x[5], y[5];
int main() {
  for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
  cout << 3 << endl;
  cout << x[0] + x[1] - x[2] << " " << y[1] + y[0] - y[2] << endl;
  cout << x[0] - x[1] + x[2] << " " << y[2] + y[0] - y[1] << endl;
  cout << x[1] - x[0] + x[2] << " " << y[1] - y[0] + y[2] << endl;
  return 0;
}
