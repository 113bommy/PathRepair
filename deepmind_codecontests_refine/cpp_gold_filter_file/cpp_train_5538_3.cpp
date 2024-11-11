#include <bits/stdc++.h>
using namespace std;
void files() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  return;
}
const int MXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
void sol() {
  int h;
  cin >> h;
  int n;
  cin >> n;
  int x[n + 1];
  for (int i = 0; i < n; ++i) cin >> x[i];
  x[n] = 0;
  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (x[i] < 2) break;
    if (x[i] == x[i + 1] + 1)
      ++i;
    else
      cnt++;
  }
  cout << cnt << "\n";
}
int main() {
  int tcase = 1;
  scanf("%d", &tcase);
  while (tcase--) {
    sol();
  }
}
