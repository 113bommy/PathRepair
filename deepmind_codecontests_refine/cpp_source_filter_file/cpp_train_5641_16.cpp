#include <bits/stdc++.h>
using namespace std;
int i, j;
void solve() {
  int b, p, f, h, c;
  cin >> b >> p >> f >> h >> c;
  int buns = 0, cost = 0;
  if (h > c) {
    if (p * 2 <= b) {
      cost += h * p;
      b -= p * 2;
    } else if (b > 1) {
      buns = b / 2;
      cost += h * buns;
      b = 0;
    }
    if (f * 2 <= b) {
      cost += f * c;
      b -= f * 2;
    } else if (b > 1) {
      buns = f / 2;
      cost += c * buns;
      b = 0;
    }
  } else {
    if (f * 2 <= b) {
      cost += f * c;
      b -= f * 2;
    } else if (b > 1) {
      buns = f / 2;
      cost += c * buns;
      b = 0;
    }
    if (p * 2 <= b) {
      cost += h * p;
      b -= p * 2;
    } else if (b > 1) {
      buns = b / 2;
      cost += h * buns;
      b = 0;
    }
  }
  cout << cost;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_case;
  cin >> test_case;
  while (test_case--) {
    solve();
    cout << "\n";
  }
  return 0;
}
