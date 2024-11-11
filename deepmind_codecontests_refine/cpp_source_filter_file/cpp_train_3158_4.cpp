#include <bits/stdc++.h>
using namespace std;
long long i, j, k, t, n, a[1000005], ma, t1, t2, t3, t4, t5, t6, t7, pa, z;
string s[1005], s1[1005];
vector<pair<string, string> > v;
map<long long, long long> mp;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> s[i] >> s1[i] >> a[i];
  }
  for (i = 1; i <= n; i++) {
    if (mp[i] == 0) {
      for (j = i; j <= n; j++) {
        if (s[i] == s1[j] && s1[i] == s[j]) {
          if (abs(a[i] - a[j]) <= k && abs(a[i] - a[j]) > 0) {
            pa = 0;
            for (z = 0; z < v.size(); z++) {
              if ((v[z].first == s[i] && v[z].second == s1[i]) ||
                  (v[z].first == s[i] || v[z].second == s1[i]))
                pa = 1;
            }
            if (pa == 0) v.push_back(make_pair(s[i], s1[i]));
            mp[i] = 1;
            mp[j] = 1;
          }
        }
      }
    }
  }
  cout << v.size() << endl;
  for (i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
