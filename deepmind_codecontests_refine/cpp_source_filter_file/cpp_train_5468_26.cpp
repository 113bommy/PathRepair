#include <bits/stdc++.h>
using namespace std;
pair<int, pair<int, int>> man[200000];
int arr[200000];
vector<int> ans;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) {
    int type, val;
    cin >> man[i].second.second >> man[i].first;
    man[i].second.first = i;
  }
  sort(man, man + m);
  sort(arr, arr + man[m - 1].first);
  int l = 0;
  int r = man[m - 1].first - 1;
  int t = man[m - 1].second.first;
  int len = man[m - 1].first;
  int type = man[m - 1].second.second;
  for (int i = m - 1; i >= 0; i--) {
    if (i == 0) {
      while (l <= r)
        if (type == 1) {
          ans.push_back(arr[r]);
          r--;
        } else {
          ans.push_back(arr[l]);
          l++;
        }
    } else if (len > man[i - 1].first) {
      for (int i = 0; i < len - man[i - 1].first; i++)
        if (type == 1) {
          ans.push_back(arr[r]);
          r--;
        } else {
          ans.push_back(arr[l]);
          l++;
        }
      if (t < man[i - 1].second.first) {
        type = man[i - 1].second.second;
        t = man[i - 1].second.first;
      }
      len = man[i - 1].first;
    }
  }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
  for (int i = man[m - 1].first; i < n; i++) cout << arr[i] << ' ';
}
