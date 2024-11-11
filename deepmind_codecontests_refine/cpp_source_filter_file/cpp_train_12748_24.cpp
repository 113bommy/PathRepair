#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 1, bg = 1;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cout << (bg + i - 1) % n + 1 << " ";
    bg = (bg + i - 1) % n + 1;
    i += 1;
  }
  return 0;
}
