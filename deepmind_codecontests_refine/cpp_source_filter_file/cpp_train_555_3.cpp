#include <bits/stdc++.h>
using namespace std;
vector<int> adia[110];
bool inc[110][110];
int main() {
  int k, n = 3;
  cin >> k;
  while (n * (n - 1) * (n - 2) / 6 <= k) n++;
  n--;
  k -= n * (n - 1) * (n - 2);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      adia[i].push_back(j);
      adia[j].push_back(i);
    }
  }
  while (k > 0) {
    n++;
    int m = 2;
    while (m * (m - 1) / 2 <= k) m++;
    m--;
    k -= m * (m - 1) / 2;
    for (int i = 1; i <= m; i++) {
      adia[i].push_back(n);
      adia[n].push_back(i);
    }
  }
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    for (auto j : adia[i]) inc[i][j] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << inc[i][j];
    cout << '\n';
  }
}
