#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
bool odd(int x) { return (x & 1); }
bool even(int x) { return !(x & 1); }
char grid[8][8];
bool A[8][8];
bool B[8][8];
int main() {
  vector<pair<int, int> > a, b;
  for (int i = 0; i < (int)(8); i++) {
    for (int j = 0; j < (int)(8); j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'W')
        a.push_back(pair<int, int>(i, j)), A[i][j] = 1;
      else if (grid[i][j] == 'B')
        b.push_back(pair<int, int>(i, j)), B[i][j] = 1;
    }
  }
  int ans1 = 0x7fffffff, ans2 = 0x7fffffff;
  for (int i = 0; i < a.size(); i++) {
    int r = a[i].first, c = a[i].second;
    bool ok = 1;
    for (int k = r; k <= 0; k--) {
      if (B[k][c]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans1 = min(ans1, abs(0 - r));
    }
  }
  for (int i = 0; i < b.size(); i++) {
    int r = b[i].first, c = b[i].second;
    bool ok = 1;
    for (int k = r; k < 8; k++) {
      if (A[k][c]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans2 = min(ans2, abs(7 - r));
    }
  }
  if (ans1 <= ans2)
    cout << "A\n";
  else
    cout << "B\n";
}
