#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, cnt[5] = {0, 0, 0, 0, 0};
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x, cnt[x]++;
  cout << cnt[4] + cnt[3] + cnt[2] / 2 + cnt[2] % 2 +
              max((cnt[1] - cnt[3] - cnt[2] % 2 + 3) / 4, 0)
       << '\n';
  return 0;
}
