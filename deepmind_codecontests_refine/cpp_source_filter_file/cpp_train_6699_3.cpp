#include <bits/stdc++.h>
using namespace std;
long long ncr(int n, int r) {
  long long C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, r); j > 0; j--) C[j] = C[j] + C[j - 1];
  }
  return C[r];
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  int hashh = 0;
  int hash2 = 0;
  int max_ = 100000000;
  int up[100000], down[100000];
  map<int, int> up_total, down_total, total;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> up[i] >> down[i];
    up_total[up[i]]++;
    total[up[i]]++;
    hashh = max(hashh, total[up[i]]);
    hash2 = max(hash2, total[down[i]]);
    if (down[i] != up[i]) {
      down_total[down[i]]++;
      total[down[i]]++;
      hash2 = max(hash2, total[down[i]]);
    }
  }
  if (hashh >= (n / 2) + (n % 2)) {
    cout << 0;
    return 0;
  }
  if (hash2 < (n / 2) + (n % 2)) {
    cout << "-1\n";
    return 0;
  }
  int ans = 100000000;
  for (std::map<int, int>::iterator iterator = total.begin();
       iterator != total.end(); iterator++) {
    if (up_total[iterator->first] >= (n / 2) + (n % 2)) {
      cout << 0;
      return 0;
    }
    if (iterator->second >= (n / 2) + (n % 2)) {
      ans = min(ans, ((n / 2) + (n % 2)) - (up_total[iterator->first]));
    }
  }
  if (ans == 100000000) {
    cout << "-1\n";
    return 0;
  }
  cout << ans;
  return 0;
}
