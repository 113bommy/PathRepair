#include <bits/stdc++.h>
using namespace std;
bool secdes(const pair<long long, long long>& a,
            const pair<long long, long long>& b) {
  if (a.second == b.second) {
    return a.first > b.first;
  } else {
    return a.second > b.second;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long ind = -1;
  long long l = s.length(), f = 0;
  for (long long i = l - 1; i >= 0; i--) {
    long long k = s[i] - 48;
    if (k % 2 == 0) {
      f += 1;
      if (f == 1) {
        ind = i;
      }
      if (s[l - 1] - 48 > k) {
        ind = i;
      }
    }
  }
  if (f == 0)
    cout << -1;
  else {
    swap(s[ind], s[l - 1]);
    cout << s;
  }
}
