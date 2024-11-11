#include <bits/stdc++.h>
using namespace std;
int degree[10005];
int main() {
  int n, a, b, i, sum = 0;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> a >> b;
    degree[a]++;
    degree[b]++;
  }
  for (i = 1; i <= n; i++) {
    sum += (degree[i] * (degree[i] - 1)) / 2;
  }
  cout << sum;
  return 0;
}
