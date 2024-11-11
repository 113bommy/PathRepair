#include <bits/stdc++.h>
using namespace std;
const long long int N = 500009;
const long long int mod = 1000000007;
long long int n, k;
string s;
string see;
vector<long long int> v;
void pre() {
  see = s;
  for (auto i : s) see += i;
  for (auto i : s) see += i;
}
int32_t main() {
  cin >> n >> k >> s;
  pre();
  for (long long int i = 0; i < 3 * n;) {
    long long int j = i;
    long long int pahla = i;
    long long int doosra = i - 1;
    long long int idharhi = 0;
    while (doosra < (3 * n - 1)) {
      if (see[i] == see[doosra + 1])
        doosra++;
      else
        break;
    }
    if (doosra == pahla) {
      i++;
      continue;
    }
    for (long long int k = i; k <= doosra; k++) {
      v.push_back(k);
    }
    i = doosra + 1;
  }
  if (v.size() == 0) {
    if (k % 2 == 0) {
      cout << s << "\n";
      return 0;
    } else {
      for (auto i : s) {
        if (i == 'A')
          cout << 'B';
        else
          cout << 'A';
      }
      cout << "\n";
      return 0;
    }
  }
  string ans = "";
  for (long long int i = n; i < 2 * n; i++) {
    auto it = lower_bound(v.begin(), v.end(), i);
    long long int is = it - v.begin();
    if (v[is] == i) {
      ans += see[i];
      continue;
    }
    is--;
    long long int dis1 = i - v[is];
    is++;
    long long int dis2 = v[is] - i;
    assert(dis1 > 0 and dis2 > 0);
    if (dis1 > k && dis2 > k) {
      if (k % 2 == 0) {
        ans += see[i];
      } else {
        if (see[i] == 'A')
          ans += 'B';
        else
          ans += 'A';
      }
      continue;
    } else if (dis1 <= k && dis1 < dis2) {
      ans += see[v[is - 1]];
    } else if (dis2 <= k && dis2 < dis1) {
      ans += see[v[is]];
    } else {
      ans += see[v[is]];
    }
  }
  assert((long long int)ans.length() == n);
  cout << ans << "\n";
}
