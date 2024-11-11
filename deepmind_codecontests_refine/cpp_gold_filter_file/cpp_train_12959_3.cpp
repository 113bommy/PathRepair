#include <bits/stdc++.h>
using namespace std;
long ar[1 << 20], station[1 << 20], dir, cur;
long long dist[1 << 20];
long n, m, cnt[1 << 20], diff;
long long ans;
long long temp;
void move1(long ps) {
  int st = station[ps];
  if (cnt[st] == 0) ++diff;
  --cnt[st];
  if (cnt[st] == 0) --diff;
}
void move2(long ps) {
  int st = station[ps];
  if (cnt[st] == 0) ++diff;
  ++cnt[st];
  if (cnt[st] == 0) --diff;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    station[i] = i;
  }
  dir = -1;
  cur = n - 1;
  for (int i = n + 1; i <= 800000; i++) {
    ar[i] = ar[cur];
    station[i] = cur;
    if (cur == 1) dir = 1;
    if (cur == n) dir = -1;
    cur += dir;
  }
  for (int i = 2; i <= 800000; i++)
    dist[i] = dist[i - 1] + abs(ar[i] - ar[i - 1]);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> temp;
    cnt[temp]++;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) diff++;
  }
  ans = -1;
  for (int i = 1; i < m; i++) {
    move1(i);
  }
  for (int i = 1; i <= 600000; i++) {
    move1(i + m - 1);
    if (diff == 0) {
      temp = dist[i + m - 1] - dist[i];
      if (ans == -1)
        ans = temp;
      else if (ans != temp) {
        ans = -2;
      }
    }
    move2(i);
  }
  if (ans < 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
  cin.get();
  cin.get();
  return 0;
}
