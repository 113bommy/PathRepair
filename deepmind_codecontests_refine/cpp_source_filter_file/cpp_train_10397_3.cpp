#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  vector<bool> a(10);
  while (k--) {
    int x;
    cin >> x;
    a[x] = true;
  }
  auto f = [&](int x) {
    while (x) {
      if (a[x % 10]) return true;
      x /= 10;
    }
    return false;
  };
  while (is_bad(n)) n++;
  cout << n;
}