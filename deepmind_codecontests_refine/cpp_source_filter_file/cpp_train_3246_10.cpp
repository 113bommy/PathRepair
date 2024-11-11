#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
int main() {
  int n, k, temp, count[1001];
  cin >> n;
  cin >> k;
  for (int i = 0; i < k; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> temp;
    count[temp]++;
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += (count[i] / 2);
  }
  int tem = ((n + 1) / 2) - ans;
  if (tem > 0) {
    ans = ans * 2 + tem;
  } else {
    ans = ans * 2;
  }
  cout << ans << "\n";
  return 0;
}
