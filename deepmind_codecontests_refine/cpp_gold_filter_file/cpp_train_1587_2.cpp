#include <bits/stdc++.h>
using namespace std;
const int G = 1000 * 500 + 10;
int a[G];
int main() {
  int n;
  cin >> n;
  fill(a, a + n + 1, 1);
  for (int i = 2; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      a[j] = i;
    }
  }
  sort(a, a + n + 1);
  for (int i = 2; i <= n; i++) cout << a[i] << ' ';
  return 0;
}
