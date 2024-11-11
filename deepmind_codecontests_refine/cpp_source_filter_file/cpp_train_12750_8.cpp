#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a;
  cin >> n;
  cin >> a;
  n = a;
  vector<int> v;
  while (n) {
    int dig = n % 10;
    if (dig == 2) {
      v.push_back(2);
    }
    if (dig == 3) {
      v.push_back(3);
    }
    if (dig == 4) {
      v.push_back(2);
      v.push_back(2);
      v.push_back(3);
    }
    if (dig == 5) {
      v.push_back(5);
    }
    if (dig == 6) {
      v.push_back(5);
      v.push_back(3);
    }
    if (dig == 7) {
      v.push_back(7);
    }
    if (dig == 8) {
      v.push_back(7);
      v.push_back(2);
      v.push_back(2);
      v.push_back(2);
    }
    if (dig == 9) {
      v.push_back(7);
      v.push_back(2);
      v.push_back(3);
      v.push_back(3);
    }
    n /= 10;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (auto x : v) cout << x;
  return 0;
}
