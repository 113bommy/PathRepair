#include <bits/stdc++.h>
using namespace std;
int n, m;
int check(int x) {
  int sum = 0;
  if (n <= ceil(x / 2)) sum++;
  if (m <= ceil(x / 3)) sum++;
  if ((n + m <= ceil(x / 2) + ceil(x / 3) - ceil(x / 6))) sum++;
  if (sum == 3) return 1;
  return 0;
}
int main() {
  cin >> n >> m;
  int x;
  x = max(2 * n, max(3 * m, (2 * n + 3 * m) / 2));
  for (int i = x; i <= 1000000; i++) {
    if (check(i)) {
      cout << i << endl;
      break;
    }
  }
}
