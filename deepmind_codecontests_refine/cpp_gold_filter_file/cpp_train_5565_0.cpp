#include <bits/stdc++.h>
using namespace std;
int n, a[1005000], l[1005000], r[1005000];
long long ans, fw[1005000];
map<int, int> ml, mr;
void update(int pos, int val) {
  for (int i = pos; i <= n; i += i & -i) fw[i] += val;
}
long long get(int pos) {
  long long res = 0;
  for (int i = pos; i > 0; i -= i & -i) res += fw[i];
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) l[i] = ++ml[a[i]];
  for (int i = n; i > 0; i--) {
    r[i] = ++mr[a[i]];
    update(r[i], 1);
  }
  for (int i = 1; i < n; i++) {
    update(r[i], -1);
    ans += get(l[i] - 1);
  }
  cout << ans;
  return 0;
}
