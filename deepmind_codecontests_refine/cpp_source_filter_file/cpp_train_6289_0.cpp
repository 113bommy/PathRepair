#include <bits/stdc++.h>
using namespace std;
const int nmax = 100100;
int n, m;
long long b[nmax], a, p[nmax];
bool check(int mid) {
  long long sum = 0;
  for (int i = 0; i < mid; i++) sum += max(0LL, p[mid - 1 - i] - b[i]);
  if (sum <= a) return true;
  return false;
}
int bs() {
  int low = 0, high = min(n, m), mid;
  while (high - low > 1) {
    mid = (high + low) / 2;
    if (check(mid))
      low = mid;
    else
      high = mid;
  }
  if (check(high)) return high;
  return low;
}
int main() {
  cin >> n >> m >> a;
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < m; i++) cin >> p[i];
  sort(p, p + m);
  sort(b, b + m);
  reverse(b, b + m);
  int answer = bs();
  long long ans2 = 0;
  for (int i = 0; i < answer; i++) ans2 += p[i];
  if (answer != 0)
    cout << answer << ' ' << max((ans2 - a), 0LL) << endl;
  else
    cout << 0 << ' ' << 0 << endl;
}
