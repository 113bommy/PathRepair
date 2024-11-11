#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <typename T>
string toString(T Number) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}
template <typename T>
T toNumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
const double PI = 2.0 * acos(0.0);
int c[5];
int n = 0;
int v;
int main() {
  ios_base::sync_with_stdio(false);
  memset(c, 0, sizeof(c));
  cin >> n;
  for (int i = 0, _n = (n); i < _n; i++) {
    cin >> v;
    c[v]++;
  }
  bool flag = true;
  int res = 0;
  if (!(c[1] || c[2])) {
    cout << 0;
    return 0;
  }
  v = min(c[2], c[1]);
  c[2] -= v;
  c[1] -= v;
  c[3] += v;
  res += v;
  v = c[2] / 3;
  if (v > 0) {
    c[2] -= v * 3;
    c[3] += v * 2;
    res += v * 2;
  }
  v = c[1] / 3;
  if (v > 0) {
    c[1] -= v * 3;
    c[3] += v;
    res += v * 2;
  }
  if (c[1] || c[2]) {
    if (c[1]) {
      if (c[1] == 1) {
        if (c[3]) {
          c[1] = 0;
          c[3]++;
          res++;
        } else {
          if (c[4] >= 2) {
            c[1] = 0;
            c[4] -= 2;
            c[3] += 3;
            res += 2;
          } else {
            cout << -1;
            return 0;
          }
        }
      } else if (c[1] == 2) {
        if (c[3] >= 2) {
          c[1] = 0;
          c[3] -= 2;
          c[4] += 2;
          res += 2;
        } else {
          c[1] = 0;
          c[2] = 1;
          res++;
        }
      }
    }
    if (c[2]) {
      if (c[2] == 1) {
        if (c[4]) {
          c[2] = 0;
          c[4]--;
          c[3]++;
          res++;
        } else {
          if (c[3] >= 2) {
            c[2] = 0;
            c[3] -= 2;
            c[4] += 2;
            res += 2;
          } else {
            cout << -1;
            return 0;
          }
        }
      } else if (c[2] == 2) {
        c[2] = 0;
        c[4]++;
        res += 2;
      }
    }
  }
  cout << res;
}
