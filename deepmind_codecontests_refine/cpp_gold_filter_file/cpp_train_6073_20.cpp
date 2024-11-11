#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int mod = 1000000007;
const double pi = acos(-1);
const int OO = INT_MAX;
int r(int x) {
  int rev = 0;
  while (x) {
    rev *= 10;
    rev += (x % 10);
    x /= 10;
  }
  return rev;
}
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  vector<int> n;
  for (int i = 1;; i++) {
    bool y = 1;
    int R = r(i);
    if (i == R) continue;
    for (int j = 2; j * j <= max(i, R); j++) {
      if (i % j == 0 || R % j == 0) {
        y = 0;
        break;
      }
    }
    if (y) n.push_back(i);
    if (n.size() == 11184) break;
  }
  int x;
  cin >> x;
  cout << n[x - 1];
}
