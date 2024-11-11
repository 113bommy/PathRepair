#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int prev = numeric_limits<int>::max();
  long long l = 0;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    if (cur != prev) {
      res += (l * (l + 1)) / 2;
      l = 0;
    }
    ++l;
    prev = cur;
  }
  res += (l * (l + 1)) / 2;
  cout << res << endl;
  return 0;
}
