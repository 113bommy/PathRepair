#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int n, m, mx, curr;
pair<long long int, long long int> p[2010];
int main() {
  cin >> n >> m;
  char ch;
  long long int str = 0;
  for (long long int i = 1; i <= n; i++) {
    long long int maxi = -1e15;
    long long int mini = 1e15;
    for (long long int j = 1; j <= m; j++) {
      cin >> ch;
      if (ch == 'W') {
        if (j > maxi) maxi = j;
        if (j < mini) mini = j;
        str = max(str, i);
      }
    }
    p[i] = make_pair(maxi, mini);
  }
  long long int cnt = 0;
  curr = 1;
  for (long long int i = 1; i <= str; i++) {
    if (i % 2 != 0) {
      if (i == str) {
        cnt += abs(p[i].first - curr);
        break;
      }
      mx = max(p[i].first, p[i + 1].first);
      if (mx == -1e15) {
        mx = curr;
        cnt++;
      } else
        cnt += abs(curr - mx) + 1;
      curr = mx;
    } else {
      if (i == str) {
        cnt += abs(p[i].second - curr);
        break;
      }
      mx = min(p[i].second, p[i + 1].second);
      if (mx == 1e15) {
        mx = curr;
        cnt++;
      } else
        cnt += abs(curr - mx) + 1;
      curr = mx;
    }
  }
  cout << cnt;
  return 0;
}
