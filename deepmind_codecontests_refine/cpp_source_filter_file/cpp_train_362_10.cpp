#include <bits/stdc++.h>
using namespace std;
int num[20];
int main() {
  int n, m;
  cin >> n >> m;
  memset(num, 0, sizeof num);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    num[a]++;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += (num[i] * num[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
