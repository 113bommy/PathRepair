#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, int> mp;
int a[555555 + 5], nstate, n;
vector<int> res[555555 + 5], ans;
bool ok = false;
long long max_val = -1e15;
long long l[555555 + 5], m[555555 + 5], w[555555 + 5], val[555555 + 5];
void show(int x) {
  if (x == 0)
    printf("MW\n");
  else if (x == 1)
    printf("LW\n");
  else
    printf("LM\n");
}
void bt1(int k, long long delta2, long long delta3, long long tot) {
  if (k == n / 2) {
    if (mp.find(pair<long long, long long>(delta2, delta3)) == mp.end()) {
      nstate++;
      mp[pair<long long, long long>(delta2, delta3)] = nstate;
      for (int i = 1; i <= k; i++) res[nstate].push_back(a[i]);
      val[nstate] = tot;
    }
    int id = mp[pair<long long, long long>(delta2, delta3)];
    if (tot > val[id]) {
      res[id].clear();
      val[id] = tot;
      for (int i = 1; i <= k; i++) res[id].push_back(a[i]);
    }
  } else {
    k++;
    a[k] = 0;
    bt1(k, delta2 - m[k], delta3 - w[k], tot);
    a[k] = 1;
    bt1(k, delta2 + l[k], delta3 + l[k] - w[k], tot + l[k]);
    a[k] = 2;
    bt1(k, delta2 + l[k] - m[k], delta3 + l[k], tot + l[k]);
  }
}
void bt2(int k, long long delta2, long long delta3, long long tot) {
  if (k == n) {
    if (mp.find(pair<long long, long long>(-delta2, -delta3)) != mp.end()) {
      int id = mp[pair<long long, long long>(-delta2, -delta3)];
      if (tot + val[id] > max_val) {
        max_val = tot + val[id];
        ans.clear();
        for (int i = 0; i < res[id].size(); i++) ans.push_back(res[id][i]);
        for (int i = n / 2 + 1; i <= n; i++) ans.push_back(a[i]);
      }
    }
  } else {
    k++;
    a[k] = 0;
    bt2(k, delta2 - m[k], delta3 - w[k], tot);
    a[k] = 1;
    bt2(k, delta2 + l[k], delta3 + l[k] - w[k], tot + l[k]);
    a[k] = 2;
    bt2(k, delta2 + l[k] - m[k], delta3 + l[k], tot + l[k]);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i] >> m[i] >> w[i];
  bt1(0, 0, 0, 0);
  bt2(n / 2, 0, 0, 0);
  if (max_val == -1e15) printf("Impossible");
  for (int i = 0; i < ans.size(); i++) show(ans[i]);
}
