#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
pair<long long, long long> p;
map<long long, long long> mp;
set<long long> s;
long long mn = INT_MAX, mx = INT_MIN;
long long n, m, tc, i, j, tmp, sum, cn, ans, res, flag;
long long a[200007];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, s1;
  cin >> s >> s1;
  long long l = s.size();
  long long f1 = 0, f2 = 0;
  if (s1.size() != l) {
    puts("NO");
    return 0;
  }
  for (i = 0; i < l; i++) {
    if (s[i] == '1') {
      f1 = 1;
      break;
    }
  }
  for (i = 0; i < l; i++) {
    if (s1[i] == '1') {
      f2 = 1;
      break;
    }
  }
  if (f1 & f2)
    puts("YES");
  else
    puts("NO");
  return 0;
}
