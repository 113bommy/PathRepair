#include <bits/stdc++.h>
using namespace std;
int a[1001], b[1001];
int f1[1001], f2[1001];
int r1[1001], r2[1001];
pair<int, int> ans1[1001], ans2[1001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  int ans = 0;
  int i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 1; i <= n; i++) f1[i] = f2[i] = r1[i] = r2[i] = i;
  for (i = n; i >= 2; i--) {
    if (a[i] == r1[i] && b[i] == r2[i]) continue;
    ans++;
    ans1[ans].first = f1[a[i]];
    ans1[ans].second = i;
    ans2[ans].first = i;
    ans2[ans].second = f2[b[i]];
    int aa = r1[i], bb = r2[i];
    swap(r1[i], r1[f1[a[i]]]);
    swap(r2[i], r2[f2[b[i]]]);
    swap(f1[a[i]], f1[aa]);
    swap(f2[b[i]], f2[bb]);
  }
  cout << ans << endl;
  for (i = 1; i <= ans; i++)
    cout << ans1[i].first << " " << ans1[i].second << " " << ans2[i].first
         << " " << ans2[i].second << endl;
  return 0;
}
