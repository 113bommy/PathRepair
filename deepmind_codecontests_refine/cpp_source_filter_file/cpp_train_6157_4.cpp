#include <bits/stdc++.h>
using namespace std;
int n;
int stx, sty, enx, eny;
int dx[100001], dy[100001];
string str;
bool solve(long long mid) {
  long long a = mid / n;
  long long b = mid % n;
  long long x = a * dx[n] + dx[b] + stx;
  long long y = a * dy[n] + dy[b] + sty;
  long long res = abs(x - enx) + abs(y - eny);
  return res <= mid;
}
int main() {
  cin >> stx >> sty >> enx >> eny >> n >> str;
  for (int i = 0; i < n; i++) {
    dy[i + 1] = dy[i];
    dx[i + 1] = dx[i];
    if (str[i] == 'U') dy[i + 1]++;
    if (str[i] == 'D') dy[i + 1]--;
    if (str[i] == 'L') dx[i + 1]--;
    if (str[i] == 'R') dx[i + 1]++;
  }
  long long head = 0, tail = 1e9 * 2, ans = -1, mid;
  while (head <= tail) {
    mid = (head + tail) >> 1;
    if (solve(mid)) {
      tail = mid - 1;
      ans = mid;
    } else {
      head = mid + 1;
    }
  }
  printf("%lld\n", ans);
}
