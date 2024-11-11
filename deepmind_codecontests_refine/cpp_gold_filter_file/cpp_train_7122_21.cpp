#include <bits/stdc++.h>
using namespace std;
int n, m, w[110];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    w[a] -= c;
    w[b] += c;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += abs(w[i]);
  cout << sum / 2 << endl;
  return 0;
}
