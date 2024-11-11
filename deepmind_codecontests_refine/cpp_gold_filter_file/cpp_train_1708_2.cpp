#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e3 + 7;
const long long mod = 1e9 + 7;
const long long inf = 1e16 + 7;
string s;
long long int ans[N], m;
vector<long long int> valid;
bool solve(long long int bal, long long int step, long long int prev) {
  if (step == m + 1) return 1;
  for (auto it = valid.begin(); it != valid.end(); it++) {
    long long int k = *it;
    if (bal - k < 0 && k != prev) {
      ans[step] = k;
      if (solve(k - bal, step + 1, k)) {
        printf("YES\n");
        for (long long int i = 1; i <= m; i++) {
          printf("%lld ", ans[i]);
        }
        exit(0);
      }
    }
  }
  return false;
}
int main() {
  long long int i, j, k;
  cin >> s;
  cin >> m;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '1') valid.push_back(i + 1);
  }
  if (solve(0, 1, -1) == false) printf("NO\n");
  return 0;
}
