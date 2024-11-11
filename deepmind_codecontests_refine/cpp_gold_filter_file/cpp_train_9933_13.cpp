#include <bits/stdc++.h>
using namespace std;
string s;
int n, cnt, k, a[150005];
pair<int, int> summ, ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) summ.first += a[i];
  ans = summ;
  for (int i = 0; i < n; i++) {
    if ((k + i) > (n - 1)) break;
    summ.first -= a[i];
    summ.first += a[k + i];
    summ.second = i + 1;
    ans = min(ans, summ);
  }
  cout << ++ans.second;
  return 0;
}
