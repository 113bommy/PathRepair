#include <bits/stdc++.h>
using namespace std;
int s[1005];
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    cin >> s[i];
    sum += s[i];
  }
  if (sum < n)
    cout << "-1";
  else if (sum - s[h] < n - 1)
    cout << "1.0";
  else {
    double ans = 1;
    s[h]--;
    sum--;
    n--;
    for (int i = 1; i <= s[h]; i++) {
      ans *= (sum - n - s[h] + i) * 1.00 / (sum - s[h] + i);
    }
    cout << 1 - ans;
  }
  return 0;
}
