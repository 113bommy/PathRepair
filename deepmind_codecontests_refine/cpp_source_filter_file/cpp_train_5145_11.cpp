#include <bits/stdc++.h>
using namespace std;
int ms[100005];
int main() {
  int k;
  cin >> k;
  vector<int> keng(k);
  for (int i = 0; i < k; i++) {
    cin >> keng[i];
    ms[keng[i] >> 1]++;
  }
  sort(keng.begin(), keng.end());
  int uk = k >> 1;
  int up = k - 1;
  int ans = k;
  for (int i = uk; i >= 0; i--) {
    if ((keng[i] << 1) <= keng[up]) {
      up--;
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
