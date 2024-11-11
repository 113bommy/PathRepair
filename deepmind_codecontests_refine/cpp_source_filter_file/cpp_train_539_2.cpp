#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, k;
  cin >> n >> l >> k;
  string x;
  cin >> x;
  sort(x.begin(), x.end());
  vector<string> ans(n);
  int pos = 0;
  int it = 0;
  for (int i = 0; i < l; i++) {
    char cmp;
    for (int j = pos; j < k; j++) {
      cmp = x[it];
      it++;
      ans[j].push_back(cmp);
    }
    for (int j = k - 1; j >= pos; j--) {
      if (ans[j].back() != cmp) {
        pos++;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int left = l - ans[i].size();
    for (int j = 0; j < left; j++) {
      ans[i].push_back(x[it]);
      it++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}
