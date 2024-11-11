#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int rank[10] = {0};
  string str[10];
  while (cin >> n >> k) {
    for (int i = 0; i < k; i++) rank[i] = i;
    for (int i = 0; i < n; i++) cin >> str[i];
    int ans = 1000000000;
    do {
      int min_ = 1000000000;
      int max_ = -1;
      for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < k; j++) {
          num = num * 10 + str[i][rank[j]] - '0';
        }
        min_ = min(min_, num);
        max_ = max(max_, num);
      }
      ans = min(ans, max_ - min_);
    } while (next_permutation(rank, rank + k));
    cout << ans << endl;
  }
  return 0;
}
