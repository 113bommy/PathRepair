#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
const long long Mod = 1e9 + 7;
int room[10];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      for (int j = 0; j <= 9; j++) {
        if (room[j] == 0) {
          room[j] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (room[j] == 0) {
          room[j] = 1;
          break;
        }
      }
    } else {
      room[s[i] - '0'] = 0;
    }
  }
  for (int i = 0; i < 10; i++) cout << room[i];
  return 0;
}
