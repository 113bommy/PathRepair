#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
    if (x % 2 == 0) x--;
  }
  for (auto data : v) cout << data << ' ';
  return 0;
}
