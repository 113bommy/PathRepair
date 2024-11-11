#include <bits/stdc++.h>
using namespace std;
int n;
queue<long long> bb[60];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    for (int j = 59; j >= 0; j--) {
      if (x >> j) {
        bb[j].push(x);
        break;
      }
    }
  }
  int cnt = 0;
  long long sum = 0;
  int ans[(int)(1e5 + 10)];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 59; j++) {
      if (!(sum & (1LL << j)) & (bb[j].size() != 0)) {
        sum ^= ans[++cnt] = bb[j].front();
        bb[j].pop();
        break;
      }
    }
    if (cnt != i) break;
  }
  if (cnt != n) {
    cout << "No"
         << "\n";
    return 0;
  }
  cout << "Yes"
       << "\n";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
