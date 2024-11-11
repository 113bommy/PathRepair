#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, count = 0, win = 0, lose = 0, draw = 0;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s >> win >> lose;
    if (win >= 2400 && lose > win) {
      return cout << "YES", 0;
    }
  }
  cout << "NO";
  return 0;
}
