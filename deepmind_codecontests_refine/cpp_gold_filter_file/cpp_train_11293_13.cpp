#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
priority_queue<long long> pq;
char a[212][212];
char b[212][212];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[j][i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      b[2 * i][2 * j] = a[i][j];
      b[2 * i + 1][2 * j] = a[i][j];
      b[2 * i + 1][2 * j + 1] = a[i][j];
      b[2 * i][2 * j + 1] = a[i][j];
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * k; j++) {
      cout << b[i][j];
    }
    cout << endl;
  }
  return 0;
}
