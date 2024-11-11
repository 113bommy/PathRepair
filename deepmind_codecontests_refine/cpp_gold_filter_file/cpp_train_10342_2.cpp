#include <bits/stdc++.h>
using namespace std;
struct app {
  int x;
  int y;
  int z;
};
app arr[10005];
int a[1005];
bool comp(app a, app b) { return a.z < b.z; }
int main() {
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  cin >> m;
  map<int, int> mp;
  for (int i = 0; i < m; i++) scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].z);
  sort(arr, arr + m, comp);
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    if (a[arr[i].x] > a[arr[i].y]) {
      if (mp[arr[i].y] == 0) {
        ans += arr[i].z;
        mp[arr[i].y] = arr[i].x;
      }
    }
  }
  int non = 0;
  for (int i = 1; i <= n; i++)
    if (mp[i] == 0) non++;
  if (non > 1)
    cout << "-1" << endl;
  else
    cout << ans << endl;
  return 0;
}
