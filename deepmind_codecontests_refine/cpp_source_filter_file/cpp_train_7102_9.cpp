#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  long long int k;
  cin >> s >> k;
  vector<long long int> v[26];
  long long int a[26] = {0};
  vector<long long int> w;
  long long int n = s.length();
  long long int x;
  string ans = "";
  if (k > ((n * (n + 1)) / 2)) {
    cout << "no such line";
    return 0;
  }
  for (long long int i = 0; i < n; i++) {
    x = (long long int)(s[i] - 'a');
    v[x].push_back(i);
    a[x] += n - i;
  }
  while (k > 0) {
    x = 0;
    long long int i = -1, y = 0, q = 0;
    while (x < k) {
      y += x;
      q = x;
      x += a[++i];
    }
    ans += (char)(97 + i);
    k -= v[i].size();
    k -= q;
    for (auto j : v[i]) {
      w.push_back(j);
    }
    for (long long int j = 0; j < 26; j++) {
      v[j].clear();
      a[j] = 0;
    }
    for (auto j : w) {
      if (j != (n - 1)) {
        x = (long long int)(s[j + 1] - 'a');
        v[x].push_back(j + 1);
        a[x] += n - (j + 1);
      }
    }
    w.clear();
  }
  cout << ans;
}
