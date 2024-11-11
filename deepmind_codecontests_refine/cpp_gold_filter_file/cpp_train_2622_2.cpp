#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<long long> ans;
  while (t > 0) {
    t--;
    string s;
    cin >> s;
    int n = s.size();
    long long total = 0;
    int ct = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        ct++;
      else {
        v[i] = ct;
        ct = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i; j < min(i + 19, n); j++) {
        long long x = 0;
        for (int k = j; k >= i; k--) {
          if (s[k] == '1') x += pow(2, j - k);
        }
        if (s[i] == '1' and x == j - i + 1) {
          total++;
        }
        if (s[i] == '1' and x > j - i + 1 and v[i]) {
          if (x - (j - i + 1) <= v[i]) {
            total++;
          }
        }
      }
    }
    ans.push_back(total);
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}
