#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int n;
int pow(int x, int d) {
  if (d == 0) return 1;
  long long p = pow(x, d / 2);
  if (d % 2 == 1)
    return ((p * p) % n) * x % n;
  else
    return (p * p) % n;
}
int main() {
  scanf("%d", &n);
  if (n == 4) {
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << 3 << endl;
    cout << 2 << endl;
    cout << 4 << endl;
    return 0;
  }
  for (int i = (2), _b = (n - 1); i <= _b; i++)
    if (n % i == 0) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  cout << 1 << endl;
  for (int i = (2), _b = (n); i <= _b; i++) {
    long long p = pow(i - 1, n - 2);
    int x = (p * i - 1) % n + 1;
    printf("%d\n", x);
  }
}
