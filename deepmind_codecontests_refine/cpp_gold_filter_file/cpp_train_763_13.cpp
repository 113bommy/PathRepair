#include <bits/stdc++.h>
using namespace std;
long long p1[1234567];
int main() {
  ios_base::sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  int a, b;
  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    ++p1[a];
    ++p1[b];
  }
  long long result = n * (n - 1) * (n - 2);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += p1[i] * (n - 1 - p1[i]);
  }
  sum /= 2;
  cout << result / 6 - sum;
  return 0;
}
