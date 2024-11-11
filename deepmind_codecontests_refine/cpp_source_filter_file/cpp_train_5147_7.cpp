#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, combi, match[1000] = {0};
  cin >> n >> k;
  combi = (n * (n - 1)) / 2;
  if (k > (n - 1) / 2) {
    cout << "-1";
    return 0;
  }
  combi = k * n;
  cout << combi << "\n";
  for (int i = 1; i <= n; i++) {
    int j = i + 1;
    if (j > n) j = 1;
    for (; j < n + 1; j++) {
      if (match[i] < k) {
        cout << i << " " << j << "\n";
        match[i]++;
      }
      if (match[i] >= k) break;
      if (j + 1 > n) j = 0;
    }
  }
  return 0;
}
