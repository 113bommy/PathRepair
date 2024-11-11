#include <bits/stdc++.h>
using namespace std;
struct Team {
  int kol, time;
} a[51];
bool cmp(Team a, Team b) {
  if (a.kol != b.kol)
    return a.kol > b.kol;
  else
    return a.time < b.time;
}
int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i].kol >> a[i].time;
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++)
    if (a[i].kol == a[k - 1].kol && a[i].time == a[k - 1].time) ans++;
  cout << ans << endl;
  return 0;
}
