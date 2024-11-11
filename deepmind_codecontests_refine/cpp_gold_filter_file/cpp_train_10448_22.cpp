#include <bits/stdc++.h>
using namespace std;
long long int pr[1000000];
int main() {
  long long int a, b, c, j, n = 1000000, sum = 0;
  cin >> a >> b >> c;
  for (int i = 2; i <= n; i++) {
    j = i;
    while (1) {
      if (j > n) break;
      pr[j]++;
      j += i;
    }
  }
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++) sum = (sum + pr[i * j * k] + 1) % 1073741824;
  cout << sum;
  return 0;
}
