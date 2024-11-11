#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, p;
  string s;
  cin >> n >> p >> s;
  if (p > n / 2) {
    reverse(s.begin(), s.end());
    p = n - p + 1;
  }
  int l = p, r = p;
  for (int i = 1; i <= p; i++) {
    if (s[i - 1] != s[n - i]) {
      l = i;
      break;
    }
  }
  for (int i = n / 2; i >= p; i--) {
    if (s[i - 1] != s[n - i]) {
      r = i;
      break;
    }
  }
  int min;
  min = p - l;
  if (p - l > r - p) {
    min = r - p;
  }
  int moves = r - l + min;
  for (int i = l; i <= r; i++) {
    if (s[i - 1] != s[n - i]) {
      int value = abs(s[i - 1] - s[n - i]);
      if (value > 13) {
        value = 26 - value;
      }
      moves += value;
    }
  }
  cout << moves << endl;
  return 0;
}
