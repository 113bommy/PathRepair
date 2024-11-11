#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int sum[N];
int main() {
  int n;
  cin >> n >> s + 1;
  int st = 0, ed = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(')
      sum[i] = sum[i - 1] - 1;
    else
      sum[i] = sum[i - 1] + 1;
    if (sum[i] == 0) {
      cnt += i - st;
      st = i;
    } else if (sum[i] > 0) {
      st = i + 1;
    }
  }
  if (sum[n])
    cout << -1 << endl;
  else
    cout << n - cnt << endl;
  return 0;
}
