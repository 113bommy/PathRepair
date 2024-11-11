#include <bits/stdc++.h>
using namespace std;
const int M = 200000;
int main() {
  int n, x, c[M];
  long long sum = 0;
  cin >> n >> x;
  c[0] = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  sort(c, c + (n + 1));
  for (int j = 1; j <= n; j++) {
    sum += (long long)(x * c[j]);
    if (x > 1) x--;
  }
  cout << sum;
  return 0;
}
