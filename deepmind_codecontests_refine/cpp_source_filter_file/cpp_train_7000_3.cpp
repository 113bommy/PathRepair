#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
long long power(long long x, long long y) {
  if (y == 0) return 1;
  return x * power(x, y - 1);
}
long long a[500005];
long long pre[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long sum = 0;
  for (int(i) = (0); (i) < ((n + 1) / 2); ++(i)) {
    cin >> a[i];
    sum += a[i];
  }
  long long x;
  cin >> x;
  sum += x * (n - (n + 1) / 2);
  if (sum > 0) {
    cout << n;
    return 0;
  }
  if (x > 0) {
    cout << -1;
    return 0;
  }
  for (int(i) = (n / 2); (i) < (n); ++(i)) {
    a[i] = x;
  }
  pre[0] = 0;
  long long ch = 0;
  for (int(i) = (1); (i) < ((n + 1) / 2 + 1); ++(i)) {
    ch += x - a[i - 1];
    pre[i] = min(pre[i - 1], ch);
  }
  int k = n;
  for (int(i) = (0); (i) < (n - (n + 1) / 2); ++(i)) {
    if (sum + pre[n - k] > 0) {
      cout << k;
      return 0;
    }
    sum -= x;
    k--;
  }
  cout << -1;
  return 0;
}
