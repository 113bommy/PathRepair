#include <bits/stdc++.h>
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int h, m;
  char c;
  string ph, pm;
  cin >> h >> c >> m;
  for (int i = (h * 60 + m) + 1; i < 1440; i++) {
    if (i == 1439) {
      cout << "00:00";
      break;
    }
    ph = to_string(i / 60);
    pm = to_string((i - (60 * h)) % 60);
    if (ph.size() == 1) ph = "0" + ph;
    if (pm.size() == 1) pm = "0" + pm;
    reverse(pm.begin(), pm.end());
    if (ph == pm) {
      reverse(pm.begin(), pm.end());
      cout << ph << ":" << pm;
      break;
    }
  }
}
