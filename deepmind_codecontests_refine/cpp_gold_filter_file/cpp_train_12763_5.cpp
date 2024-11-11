#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 7;
int n;
int p[MAXN];
int cur[MAXN * 2];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  int L = 0, R = 0;
  long long sum = 0;
  for (int i = 1; i < n + 1; i++) {
    cin >> p[i];
    sum += abs(p[i] - i);
    if (p[i] >= i)
      L++, cur[p[i] - i]++;
    else
      R++;
  }
  long long ans = sum;
  int pos = 0;
  for (int i = 0; i < n - 1; i++) {
    L -= cur[i];
    R += cur[i];
    sum = sum - L + R - abs(p[n - i] - n - 1) + p[n - i] - 1;
    cur[p[n - i] + i]++;
    L++, R--;
    if (sum < ans) ans = sum, pos = i + 1;
  }
  cout << ans << ' ' << pos << endl;
  return 0;
}
