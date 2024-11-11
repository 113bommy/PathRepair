#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000007;
const int MAX_N = 101000;
string s;
int flag[MAX_N];
int f(int t) {
  int n = s.length();
  for (int i = 0; i < n; i++) flag[i] = 0;
  int l = -1, x, y = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      if (l != -1) {
        if (t < i - l) return 0;
        x = max(t - 2 * (i - l), (t - i + l) / 2) + i;
        for (int j = l; j <= min(x, n - 1); j++) flag[j] = 1;
      } else {
        x = i + t;
        for (int j = y + 1; j <= min(x, n - 1); j++) flag[j] = 1;
      }
      y = max(y, min(x, n - 1));
      l = -1;
    }
    if (s[i] == '*') {
      if (l == -1 && flag[l] == 0) l = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (flag[i] == 0 && s[i] == '*') return 0;
  }
  return 1;
}
int main() {
  int n, l, r, mid;
  cin >> n;
  cin >> s;
  l = 0;
  r = 3 * n + 1;
  for (int i = 0; i < 30; i++) {
    mid = (l + r) / 2;
    if (f(mid) == 1)
      r = mid;
    else
      l = mid + 1;
  }
  for (int i = max(0, l - 20); i < max(l, r) + 200; i++) {
    if (f(i) == 1) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
