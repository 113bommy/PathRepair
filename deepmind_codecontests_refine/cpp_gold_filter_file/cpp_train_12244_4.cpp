#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  char mass[n];
  for (int i(0); i < n; ++i) cin >> mass[i];
  int MAXN = 26;
  int value[MAXN];
  for (int i(0); i < MAXN; i++) value[i] = 0;
  for (int i(0); i < n; ++i) {
    if (mass[i] <= 90)
      ++value[mass[i] - 65];
    else
      ++value[mass[i] - 97];
  }
  for (int i(0); i < MAXN; ++i) {
    if (value[i] > k) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
