#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 25;
void io() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& s) {
  return os << '(' << s.first << ',' << s.second << ')';
}
const int MOD = 1000000007;
const double EPS = 1e-8;
string a, b;
bool check(int sa, int sb, int size) {
  if (size % 2 == 0) {
    for (int i = 0; i < size; i++) {
      if (a[sa + i] != b[sb + i]) return 0;
    }
    return 1;
  }
  return (check(sa, sb, size / 2) &&
          check(sa + size / 2, sb + size / 2, size / 2)) ||
         (check(sa + size / 2, sb, size / 2) &&
          check(sa, sb + size / 2, size / 2));
}
int main() {
  io();
  cin >> a >> b;
  int length = a.size();
  if (check(0, 0, length)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
