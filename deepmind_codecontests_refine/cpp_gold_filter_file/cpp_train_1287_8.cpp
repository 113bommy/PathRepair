#include <bits/stdc++.h>
using namespace std;
int s[100005];
int main() {
  int i, n, sum;
  while (cin >> n) {
    for (i = sum = 0; i < n; i++) {
      scanf("%d", &s[i]);
      sum += s[i];
    }
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    if (sum % n == 0)
      cout << n << endl;
    else
      cout << n - 1 << endl;
  }
  return 0;
}
