#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool check(string s, vector<long long>& ans) {
  string temp = s;
  sort(temp.begin(), temp.end());
  long long n = (long long)s.size();
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = 0; j < n - i - 1; j++) {
      if (s[j] > s[j + 1]) {
        if (ans[j] ^ ans[j + 1]) {
          swap(s[j], s[j + 1]);
          swap(ans[j], ans[j + 1]);
        } else {
          return false;
        }
      }
    }
  }
  return s == temp;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<char, long long>> v;
  for (long long i = 0; i < n; i++) {
    v.push_back({s[i], i});
  }
  vector<long long> ans(n, -1);
  bool flag = true;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = 0; j < n - i - 1; j++) {
      if (v[j].first > v[j + 1].first) {
        long long idx1 = v[j].second, idx2 = v[j + 1].second;
        if (ans[idx1] != -1 && ans[idx2] != -1) {
          if (ans[idx1] ^ ans[idx2]) {
            continue;
          } else {
            flag = false;
            break;
          }
        } else if (ans[idx1] != -1) {
          ans[idx2] = ans[idx1] ^ 1;
        } else if (ans[idx2] != -1) {
          ans[idx1] = ans[idx2] ^ 1;
        } else {
          ans[idx1] = 0;
          ans[idx2] = 1;
        }
        swap(v[j], v[j + 1]);
      }
    }
    if (!flag) break;
  }
  for (long long i = 0; i < n; i++)
    if (ans[i] == -1) ans[i] = 0;
  if (check(s, ans)) {
    cout << "YES"
         << "\n";
    for (long long x : ans) {
      cout << x;
    }
    cout << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}
