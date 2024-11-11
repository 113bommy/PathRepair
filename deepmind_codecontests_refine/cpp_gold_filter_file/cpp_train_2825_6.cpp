#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> d[1000016];
long long dp(long long i) {
  if (i == 0) return 0;
  if (i < 0) return 9000000000000000000;
  if (d[i].first) return d[i].first;
  long long val = dp(i - 7);
  long long val2 = dp(i - 4);
  if (val >= val2 || val == 9000000000000000000) {
    d[i].second = 4;
    return d[i].first = 1 + val2;
  } else {
    d[i].second = 7;
    return d[i].first = 1 + val;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, n;
  cin >> n;
  dp(n);
  if (d[n].first >= 9000000000000000000)
    cout << "-1\n";
  else {
    while (n > 0) {
      cout << d[n].second;
      n -= d[n].second;
    }
  }
  return 0;
}
