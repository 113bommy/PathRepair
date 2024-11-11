#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2 * 100000 + 10;
int cows[Maxn] = {0};
int tozi[Maxn] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> cows[i];
  tozi[0] = cows[0];
  for (int i = 1; i < n; i++) tozi[i] = tozi[i - 1] + cows[i];
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!cows[i]) ans += tozi[i];
  }
  cout << ans << endl;
  return 0;
}
