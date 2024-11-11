#include <bits/stdc++.h>
using namespace std;
pair<int, int> c[600];
bool solve() {
  long long n, h;
  cin >> h >> n;
  long long mah = 1 << h;
  double curr = mah / 2 + .5;
  long long res = 1;
  bool left = true;
  while (1) {
    if (mah == 1) {
      break;
    }
    if (n < curr) {
      curr -= mah / 4;
      res += left ? 1 : mah;
      if (left) left = !left;
    } else {
      curr += mah / 4;
      res += left ? mah : 1;
      if (!left) left = !left;
    }
    mah /= 2;
  }
  cout << (res - 1) << endl;
  return true;
}
int main() {
  long long t = 1;
  ios_base::sync_with_stdio(false);
  for (long long i = 0; i < t; i++) {
    if (solve()) {
    } else
      cout << "No" << endl;
  }
  return 0;
}
