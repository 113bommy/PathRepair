#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int cnt[105];
int pre[maxn * 3];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int mmax = 0;
  int id = 0;
  for (int i = 1; i <= n; i++) {
    if (++cnt[a[i]] > mmax) {
      mmax = cnt[a[i]];
      id = a[i];
    } else if (cnt[a[i]] == mmax)
      id = -1;
  }
  if (id == -1) {
    cout << n << endl;
    return 0;
  }
  int res = 0;
  for (int i = 1; i <= 100; i++) {
    if (i == id) continue;
    vector<int> v;
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] == i)
        sum++;
      else if (a[j] == id)
        sum--;
      v.push_back(sum + 200005);
      if (sum != 0 && pre[sum + 200005] == 0)
        pre[sum + 200005] = j;
      else
        res = max(res, j - pre[sum + 200005]);
    }
    for (auto to : v) pre[to] = 0;
  }
  cout << res << endl;
  return 0;
}
