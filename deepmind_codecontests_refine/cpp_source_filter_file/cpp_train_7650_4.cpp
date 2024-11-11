#include <bits/stdc++.h>
using namespace std;
bool check(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int a[1001];
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  int h = 0;
  for (int i = 2; i < n; i++) {
    if (check(i)) {
      int x = i;
      while (x <= n) {
        a[h] = x;
        x *= i;
        h++;
      }
    }
  }
  cout << h << endl;
  for (int i = 0; i < h; i++) {
    cout << a[i] << ' ';
  }
}
