#include <bits/stdc++.h>
using namespace std;
const int MOD = 95542721;
const int INF = 2e9;
const long long INF64 = 4e18;
const long double EPS = 1e-16;
const long long MD = 1e9 + 7;
const long long T = 2543;
const int N = 2001;
const int M = 1001;
const int DEBUG = 0;
const int MAGIC = 320;
int get(int first, int second) {
  cout << first << ' ' << second << endl;
  fflush(stdout);
  string s;
  cin >> s;
  if (s == "white")
    return 0;
  else
    return 1;
}
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    get(0, 0);
    cout << 1 << ' ' << 0 << ' ' << 1 << ' ' << 1 << endl;
    return 0;
  }
  int q1 = get(0, 0);
  int q2 = get(0, 1000000000);
  if (q1 != q2) {
    int l = 0, r = 1000000000;
    for (int i = 0; i < int(n - 2); i++) {
      int m = (l + r) / 2;
      int first = get(m, 0);
      if (first == q1)
        l = m;
      else
        r = m;
    }
    cout << l + 1 << ' ' << 0 << ' ' << l + 1 << ' ' << 1 << endl;
  } else {
    int l = 0, r = 1000000001;
    for (int i = 0; i < int(n - 2); i++) {
      int m = (l + r) / 2;
      int first = get(0, m);
      if (first == q1)
        l = m;
      else
        r = m;
    }
    cout << 0 << ' ' << l + 1 << ' ' << 1 << ' ' << l + 1 << endl;
  }
  return 0;
}
