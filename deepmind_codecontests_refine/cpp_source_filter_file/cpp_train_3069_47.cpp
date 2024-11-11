#include <bits/stdc++.h>
using namespace std;
inline long long modExp(long long a, long long b, long long m = 998244353) {
  long long res = 1;
  a %= m;
  while (b >= 1) {
    if (b % 2 != 0) {
      res = (res % m * a % m) % m;
    }
    a = (a % m * a % m) % m;
    b = b / 2;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  map<char, int> m = {{'Q', 9}, {'R', 5}, {'B', 3}, {'K', 3},
                      {'P', 1}, {'K', 0}, {'.', 0}};
  int white = 0, black = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char c;
      cin >> c;
      if ('A' <= c && c <= 'Z') {
        white += m[c];
      } else {
        black += m[c - 32];
      }
    }
  }
  if (black > white) {
    cout << "Black\n";
  } else if (white > black) {
    cout << "White\n";
  } else {
    cout << "Draw\n";
  }
  return 0;
}
