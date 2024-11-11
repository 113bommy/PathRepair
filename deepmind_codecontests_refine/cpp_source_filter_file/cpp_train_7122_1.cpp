#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, c;
  cin >> n >> m;
  int my[n];
  for (int i = 0; i < n; i++) my[i] = 0;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    my[a - 1] += c;
    my[b - 1] -= c;
  }
  int sum = 0;
  for (int i = 0; i < m; i++) {
    if (my[i] > 0) sum += my[i];
  }
  cout << sum;
  return 0;
}
