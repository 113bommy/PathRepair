#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int res[100010];
  int val = n;
  for (int i = n - k; i <= n; i++) res[i] = val--;
  for (int i = n - k - 1; i >= 1; i--) res[i] = val--;
  for (long long i = 1; i <= n; i++) cout << res[i] << " ";
  return 0;
}
