#include <bits/stdc++.h>
using namespace std;
const long long MAX = 300001;
long long n, k, cnt[MAX], mask[MAX], inf = 9999999;
string s;
int main() {
  cin >> s;
  n = s.size();
  set<long long> zeros;
  set<long long> ones;
  vector<vector<long long>> ans;
  zeros.insert(inf);
  ones.insert(inf);
  long long cnt1 = 0, cnt0 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ones.insert(i);
      cnt1++;
    } else {
      zeros.insert(i);
      cnt0++;
    }
  }
  long long w = 0;
  vector<long long> tmp;
  tmp.push_back(*zeros.lower_bound(0));
  if (tmp[0] != inf) {
    zeros.erase(tmp[0]);
    cnt0 -= 1;
  }
  while (cnt0 > 0) {
    if (w == 0) {
      long long a = *ones.lower_bound(tmp[tmp.size() - 1]);
      if (a == inf) {
        ans.push_back(tmp);
        tmp.clear();
        a = *zeros.lower_bound(0);
        zeros.erase(a);
        tmp.push_back(a);
        cnt0 -= 1;
        continue;
      } else {
        tmp.push_back(a);
        ones.erase(a);
        cnt1 -= 1;
      }
    } else {
      long long a = *zeros.lower_bound(tmp[tmp.size() - 1]);
      if (a == inf) {
        cout << -1;
        return 0;
      } else {
        tmp.push_back(a);
        zeros.erase(a);
        cnt0 -= 1;
      }
    }
    w ^= 1;
  }
  if (cnt1 != 0) {
    cout << -1;
    return 0;
  }
  if (tmp.size() != 1) ans.push_back(tmp);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
