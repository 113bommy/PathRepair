#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, p;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    if (p > 0) {
      ++c;
    }
    cin >> p;
  }
  cout << (c < 2 || n - c < 2 ? "Yes" : "No");
  return 0;
}
