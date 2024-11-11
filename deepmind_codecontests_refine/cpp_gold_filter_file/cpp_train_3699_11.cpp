#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e9 + 999999;
const long long Mod = (long long)1e9 + 7;
const long long MaXN = (long long)1e18;
const int N = (int)1e6 + 7;
const int MaXI = (int)1e9;
const int Mass = (int)2e5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int b = 0, g = 0, r = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') {
      b++;
    }
    if (s[i] == 'G') {
      g++;
    }
    if (s[i] == 'R') {
      r++;
    }
  }
  if (b == n) {
    cout << 'B';
    return 0;
  } else if (g == n) {
    cout << 'G';
    return 0;
  } else if (r == n) {
    cout << 'R';
    return 0;
  }
  if (r > 1 || g > 1) {
    cout << 'B';
  } else if (r == 1 && g == 1) {
    cout << 'B';
  }
  if (b > 1 || r > 1) {
    cout << 'G';
  } else if (b == 1 && r == 1) {
    cout << 'G';
  }
  if (b > 1 || g > 1) {
    cout << 'R';
  } else if (b == 1 && g == 1) {
    cout << 'R';
  }
  return 0;
}
