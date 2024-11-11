#include <bits/stdc++.h>
using namespace std;
int countSetBits(unsigned int n) {
  unsigned int count1 = 0;
  while (n) {
    count1++;
    n >>= 1;
  }
  return count1;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  int army[m + 2];
  for (int i = 1; i <= m + 1; i++) {
    cin >> army[i];
  }
  int fedor_bits = countSetBits(army[m + 1]);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int cnt = 0;
    int fedor = army[m + 1];
    int curr = army[i];
    int j = 0;
    int curr_bits = countSetBits(curr);
    while (j < min(curr_bits, fedor_bits)) {
      int a = fedor % 2;
      int b = curr % 2;
      if (fedor % 2 != curr % 2) {
        cnt++;
      }
      fedor >>= 1;
      curr >>= 1;
      j++;
    }
    if (cnt <= k) ans++;
  }
  cout << ans << endl;
  return 0;
}
