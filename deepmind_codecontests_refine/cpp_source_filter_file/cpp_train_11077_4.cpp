#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long double pi = 3.14159265358979323846;
const int inf = (int)1e9;
const int ss = (int)1e6 + 3;
const int base = inf;
bool pred(const pair<int, int>& i, const pair<int, int>& j) {
  if (i.first == j.first) {
    return i.second > j.second;
  } else {
    return i.first > j.first;
  }
}
bool pred1(const string& i, const string& j) { return i.size() > j.size(); }
int main() {
  int n, m, s, f;
  cin >> n >> m >> s >> f;
  char c;
  int sign = 0;
  if (s > f) {
    c = 'L';
    sign = -1;
  } else {
    c = 'R';
    sign = 1;
  }
  int now = 1;
  int k = abs(s - f);
  for (int i = 0; i < m; ++i) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if (t > now) {
      for (int j = 0; j < t - now && k >= 0; ++j, --k) {
        cout << c;
        s += sign;
      }
      now = t;
    }
    ++now;
    if (k == 0) {
      break;
    }
    int s1 = s + sign;
    if ((s < l || s > r) && (s1 < l || s1 > r)) {
      s += sign;
      --k;
      cout << c;
    } else {
      cout << "X";
    }
    if (k == 0) {
      break;
    }
  }
  while (k > 0) {
    cout << c;
    --k;
  }
  return 0;
}
