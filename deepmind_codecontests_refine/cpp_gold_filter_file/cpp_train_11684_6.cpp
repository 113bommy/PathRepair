#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * (b / gcd(a, b));
}
int ROW[] = {+1, -1, +0, +0};
int COL[] = {+0, +0, +1, -1};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main() {
  int t;
  cin >> t;
lol:
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      sum = 0;
      for (int j = i; j < n; j++) {
        sum += a[j];
        if (sum % 2 == 0) {
          cout << j - i + 1 << endl;
          for (int k = i + 1; k <= j + 1; k++) {
            cout << k << " ";
          }
          printf("\n");
          goto lol;
        }
      }
    }
    cout << -1 << endl;
  }
}
