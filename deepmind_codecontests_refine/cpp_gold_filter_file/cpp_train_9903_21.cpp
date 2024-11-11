#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int tmp;
  cin >> n >> k;
  map<int, int> cnt;
  vector<int> ans;
  vector<int> choice(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> choice[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (cnt.count(choice[i]) == 0) {
      cnt[choice[i]] = tmp;
    } else {
      if (cnt[choice[i]] > tmp)
        ans.push_back(tmp);
      else {
        ans.push_back(cnt[choice[i]]);
        cnt[choice[i]] = tmp;
      }
    }
  }
  int remain = k - cnt.size();
  sort(ans.begin(), ans.end());
  long long ans0 = 0;
  for (int i = 0; i < remain; i++) ans0 += ans[i];
  cout << ans0 << endl;
  return 0;
}
