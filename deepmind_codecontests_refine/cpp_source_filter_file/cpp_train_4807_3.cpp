#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, num[maxn];
bool vis[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
  }
  sort(num, num + n);
  if (num[n - 1] >= num[n - 2] + num[n - 3]) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  int tar = lower_bound(num, num + n - 2, num[n - 1] - num[n - 2]) - num;
  cout << num[tar] << ' ' << num[n - 1] << ' ' << num[n - 2] << ' ';
  for (int i = n - 3; i >= 0; --i) {
    if (i == tar) {
      continue;
    }
    cout << num[i] << ' ';
  }
  return 0;
}
