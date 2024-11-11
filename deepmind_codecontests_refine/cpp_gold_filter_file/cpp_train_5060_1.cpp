#include <bits/stdc++.h>
using namespace std;
set<int> gg;
int main() {
  int k, n, a[2010], b[2010];
  cin >> k >> n;
  a[0] = 0;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) cin >> b[i];
  sort(a + 1, a + k + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= k; i++) {
    int flag = b[1] - a[i];
    int sum = 2;
    for (int j = i + 1; j <= k; j++)
      if (b[sum] - a[j] == flag) sum++;
    if (sum == n + 1) gg.insert(flag);
  }
  cout << gg.size() << endl;
  return 0;
}
