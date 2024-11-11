#include <bits/stdc++.h>
using namespace std;
const bool print = false;
const int N = 57;
const long long mod = 1e9 + 7;
int main() {
  int i, j, n;
  scanf("%d", &n);
  int p = 0;
  for (i = 0; i <= n && i <= 8; i++) {
    p += n - i + 1;
    if (i < 8)
      for (j = 0; j <= n - i && j <= 4; j++) p += n - i - j;
  }
  cout << p;
  return 0;
}
