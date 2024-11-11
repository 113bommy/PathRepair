#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>>::iterator ptr;
long long count = 0;
long long cache[10004];
long long dp[100005] = {0};
long long v[200005] = {0};
long long a[200005] = {0};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  map<long long, long long> m;
  m[25] = 0;
  m[50] = 0;
  m[75] = 0;
  m[100] = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 25) {
      m[25]++;
    } else if (a[i] - 25 != 75 && m[a[i] - 25] == 0 && a[i] != 25) {
      cout << "NO";
      return 0;
    } else {
      m[a[i]]++;
      if (a[i] - 25 != 75)
        m[a[i] - 25]--;
      else {
        if (m[50] > 0 && m[25] > 0) {
          m[50]--;
          m[25]--;
        } else if (m[25] >= 3) {
          m[25] -= 3;
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
