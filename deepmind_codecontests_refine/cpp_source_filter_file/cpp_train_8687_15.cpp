#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(m + 1);
  for (int i = 0; i <= m; i++) {
    cin >> arr[i];
  }
  int count = 0;
  int lcount;
  int temp;
  for (int i = 0; i < m; i++) {
    temp = arr[i] ^ arr[m];
    lcount = 0;
    for (int j = 0; j <= n; j++) {
      if (temp & 1 << n) lcount++;
    }
    if (lcount <= k) count++;
  }
  cout << count << "\n";
  return 0;
}
