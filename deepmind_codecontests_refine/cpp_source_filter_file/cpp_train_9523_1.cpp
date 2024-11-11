#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, arr[55], n, m, pos, num;
  long long int fc[55];
  cin >> n >> m;
  fc[1] = (long long int)1;
  for (i = 2; i <= 50; i++) {
    fc[i] = fc[i - 1] * (1LL) * 2;
  }
  pos = 0;
  num = 1;
  i = 1;
  j = n;
  while (1) {
    if (pos == n) break;
    if (m <= fc[n - pos - 1]) {
      arr[i] = num;
      num++;
      i++;
    } else {
      arr[j] = num;
      num++;
      j--;
      m = m - fc[n - pos - 1];
    }
    pos++;
  }
  for (i = 1; i <= n; i++) cout << arr[i] << " ";
  return 0;
}
