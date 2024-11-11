#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int mod = 1e9 + 7;
long long int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, ans1 = 0,
              ans2 = 0, ans3 = 0;
void solve() {
  long long int n, k;
  cin >> n >> k;
  string s1;
  cin >> s1;
  cnt1 = 0;
  cnt2 = n / 2;
  vector<pair<long long int, long long int> > v1;
  long long int z1 = (n / 2);
  k -= 1;
  z1 -= (k);
  long long int z2 = k;
  for (long long int i = 0; i < 2 * z2; i++) {
    if (k > 0) {
      if (i % 2 == 0) {
        if (s1[i] == '(') {
          cnt2--;
          cnt1++;
        } else {
          cnt2--;
          string s2 = s1;
          for (long long int j = i + 1; j < n; j++) {
            if (s1[j] == '(') {
              v1.push_back(make_pair(i + 1, j + 1));
              long long int cc1 = 0;
              for (long long int k = i; k < j + 1; k++) {
                s1[k] = s2[j - cc1];
                cc1++;
              }
              break;
            }
          }
        }
      } else {
        if (s1[i] == ')') {
        } else {
          string s2 = s1;
          for (long long int j = i + 1; j < n; j++) {
            if (s1[j] == ')') {
              v1.push_back(make_pair(i + 1, j + 1));
              long long int cc1 = 0;
              for (long long int k = i; k < j + 1; k++) {
                s1[k] = s2[j - cc1];
                cc1++;
              }
              break;
            }
          }
        }
        k--;
      }
    }
  }
  cnt1 = z1;
  for (long long int i = 2 * z2; i < n; i++) {
    if (cnt2 > 0) {
      if (s1[i] == '(') {
        cnt2--;
      } else {
        string s2 = s1;
        for (long long int j = i + 1; j < n; j++) {
          if (s1[j] == '(') {
            v1.push_back(make_pair(i + 1, j + 1));
            long long int cc1 = 0;
            for (long long int k = i; k < j + 1; k++) {
              s1[k] = s2[j - cc1];
              cc1++;
            }
            break;
          }
        }
      }
    } else {
      if (s1[i] == ')') {
      } else {
        string s2 = s1;
        for (long long int j = i + 1; j < n; j++) {
          if (s1[j] == '(') {
            v1.push_back(make_pair(i + 1, j + 1));
            long long int cc1 = 0;
            for (long long int k = i; k < j + 1; k++) {
              s1[k] = s1[j - cc1];
              cc1++;
            }
            break;
          }
        }
      }
    }
  }
  cout << v1.size() << endl;
  for (long long int i = 0; i < v1.size(); i++) {
    cout << v1[i].first << " " << v1[i].second << endl;
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
