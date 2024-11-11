#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, long long>& a, pair<string, long long>& b) {
  return a.second < b.second;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
int32_t main() {
  long long n, k;
  cin >> n >> k;
  vector<string> s(n);
  map<string, long long> cnt;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    cnt[s[i]]++;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      string need;
      for (long long c = 0; c < k; c++) {
        if (s[i][c] == s[j][c]) {
          need += s[i][c];
        } else if ((s[i][c] == 'S' && s[j][c] == 'E') ||
                   (s[i][c] == 'E' && s[j][c] == 'S')) {
          need += 'T';
        } else if ((s[i][c] == 'S' && s[j][c] == 'T') ||
                   (s[i][c] == 'T' && s[j][c] == 'S')) {
          need += 'E';
        } else if ((s[i][c] == 'T' && s[j][c] == 'E') ||
                   (s[i][c] == 'E' && s[j][c] == 'T')) {
          need += 'S';
        }
      }
      if (cnt[need] > 0) {
        ans += cnt[need];
      }
    }
  }
  cout << ans / 3;
  return 0;
}
