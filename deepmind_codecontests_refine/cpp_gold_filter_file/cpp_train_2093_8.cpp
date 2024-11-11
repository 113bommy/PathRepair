#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAX = 1e6;
int sum[200];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i <= 900; i++) {
    int sum = 0, cnt = 0;
    for (int j = 0; j < n; j++) {
      sum += (s[j] - 48);
      if (sum == i)
        sum = 0, cnt++;
      else if (sum > i)
        break;
    }
    if (sum == 0 && cnt > 1) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
