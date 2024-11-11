#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 1, bg = 1;
  cin >> n;
  for (int j = 1; j < n; ++j) {
    cout << (bg + i - 1) % n + 1 << " ";
    bg = (bg + i - 1) % n + 1;
    i += 1;
  }
  return 0;
}
