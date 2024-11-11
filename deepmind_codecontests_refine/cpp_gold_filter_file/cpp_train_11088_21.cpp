#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int INF = 1e9 + 9;
int n;
char a[N];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  bool flag = 0;
  int cnt = 0;
  vector<int> v;
  for (int i = int(1); i <= int(n); ++i) {
    cin >> a[i];
    if (a[i] != a[i - 1]) {
      if (i > 1) v.push_back(cnt);
      cnt = 1;
    } else
      ++cnt;
  }
  v.push_back(cnt);
  int ans = v.size();
  cnt = 0;
  for (int i = int(0); i <= int(ans - 1); ++i) {
    if (v[i] >= 3) flag = 1;
    if (v[i] >= 2) ++cnt;
  }
  if (cnt >= 2) flag = 1;
  if (flag)
    cout << ans + 2 << "\n";
  else
    cout << ans + min(1, cnt) << "\n";
  return 0;
}
