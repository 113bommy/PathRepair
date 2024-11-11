#include <bits/stdc++.h>
using namespace std;
int n, k, tmp, z, j, i, last;
int usg(int a, int b) {
  if (a == 0 || b == 0) return a + b;
  if (a > b)
    return usg(b, a % b);
  else
    return usg(a, b % a);
}
int main() {
  cin >> n >> k;
  if (n / 2 > k) {
    cout << "-1" << endl;
    return 0;
  };
  if (n == 1 && k > 0) {
    cout << "-1" << endl;
    return 0;
  };
  if (n == 1 && k == 0) {
    cout << "1" << endl;
    return 0;
  };
  z = n / 2;
  for (i = 1; i < z; i++) printf("%d %d ", i * 2 - 1, i * 2);
  last = (z - 1) * 2;
  z = k - (z - 1);
  j = 0;
  while (j * z <= last) j++;
  printf("%d %d ", j * z, (j + 1) * z);
  if (n % 2 == 1) printf("1000000000\n");
}
