#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int value[80];
  int cur = 1;
  int i = 1;
  int sum = 3;
  while (cur <= 60) {
    while (cur < sum) {
      value[cur] = i;
      cur++;
    }
    i++;
    sum += (i + 1);
  }
  int n;
  cin >> n;
  int a;
  long long ans;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i == 0) {
      ans = value[a];
    } else {
      ans = (ans ^ value[a]);
    }
  }
  if (n == 1) {
    cout << "NO" << flush;
    return 0;
  }
  if (ans == 0) {
    cout << "YES" << flush;
    return 0;
  }
  cout << "NO" << flush;
  return 0;
}
