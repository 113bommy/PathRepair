#include <bits/stdc++.h>
using namespace std;
const long long INF = LONG_LONG_MAX;
const long long NINF = LONG_LONG_MIN;
const long long mmod = 1000000007;
bool check(string& a, string& b) {
  long long j = 0;
  for (long long i = 0; i < (long long)b.size() && j < (long long)a.size();
       i++, j++) {
    if (b[i] != a[j]) return false;
  }
  return (j == (long long)a.size());
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t-- > 0) {
    string s, c;
    cin >> s >> c;
    string temp = s;
    sort((temp).begin(), (temp).end());
    for (long long i = 0; i < (long long)s.size(); i++) {
      if (temp[i] != s[i]) {
        long long max_id = i;
        for (long long j = i + 1; j < (long long)s.size(); j++) {
          if (s[max_id] > s[j]) max_id = j;
        }
        swap(s[max_id], s[i]);
        break;
      }
    }
    if (s > c)
      cout << "---" << endl;
    else
      cout << s << endl;
  }
}
