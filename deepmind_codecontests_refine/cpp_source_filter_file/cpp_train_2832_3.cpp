#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int KINF = 0x3f3f3f3f;
constexpr double eps = 1e-7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> mp1(26), mp2(26);
    for (char& c : s) mp1[c - 'a']++;
    for (char& c : t) mp2[c - 'a']++;
    bool ok = true;
    for (int i = (int)0; i < (int)26; ++i) {
      if (mp1[i] != mp2[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    ok = false;
    for (int i = (int)0; i < (int)26; ++i) {
      if (mp1[i] >= 2) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
      continue;
    }
    vector<long long> sum1(28), sum2(28);
    auto update = [&](int x, vector<long long>& sum) {
      for (int i = x; i <= n; i += (i & (-i))) sum[i] += 1;
    };
    auto query = [&](int x, vector<long long>& sum) {
      long long res = 0;
      while (x) {
        res += sum[x];
        x &= (x - 1);
      }
      return res;
    };
    long long inv1 = 0, inv2 = 0;
    for (int i = (int)n - 1; i > (int)-1; i--) {
      int ss = s[i] - 'a' + 1, tt = t[i] - 'a' + 1;
      inv1 += query(ss - 1, sum1);
      inv2 += query(tt - 1, sum2);
      update(ss, sum1);
      update(tt, sum2);
    }
    cout << (abs(inv1 - inv2) % 2 == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
