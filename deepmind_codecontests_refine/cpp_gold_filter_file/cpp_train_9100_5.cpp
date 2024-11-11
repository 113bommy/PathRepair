#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, i, sum, j, r = 1, B[20][20];
char A[20][20];
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> x;
    sum += x;
  }
  if (sum == 0)
    cout << 0;
  else {
    if (abs(sum) <= m)
      cout << "1";
    else
      cout << (abs(sum) / m) + (abs(sum) % m != 0);
  }
  return 0;
}
