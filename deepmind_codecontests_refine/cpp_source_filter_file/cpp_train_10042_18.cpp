#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < 30; i++) {
    if (i * (i + 1) / 2 == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
