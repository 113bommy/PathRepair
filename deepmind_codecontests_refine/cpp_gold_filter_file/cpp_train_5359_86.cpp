#include <bits/stdc++.h>
using namespace std;
int boy[110];
int girl[110];
int main() {
  int n, m, b, g, i, sum;
  memset(boy, 0, sizeof(boy));
  memset(girl, 0, sizeof(girl));
  cin >> n >> m;
  cin >> b;
  for (i = 0; i < b; i++) {
    cin >> sum;
    boy[sum] = 1;
  }
  cin >> g;
  for (i = 0; i < g; i++) {
    cin >> sum;
    girl[sum] = 1;
  }
  for (i = 0; i < 2 * n * m; i++) {
    if (boy[i % n] == 1 || girl[i % m] == 1) boy[i % n] = girl[i % m] = 1;
  }
  sum = 0;
  for (i = 0; i < n; i++)
    if (boy[i] == 1) sum++;
  for (i = 0; i < m; i++)
    if (girl[i] == 1) sum++;
  if (sum == n + m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
