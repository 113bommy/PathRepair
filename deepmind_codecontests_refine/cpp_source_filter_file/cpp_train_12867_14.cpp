#include <bits/stdc++.h>
using namespace std;
vector<long long> vv;
struct node {
  long long dur, l, r, cost;
};
node arr[200005];
vector<long long> tmp1, tmp2;
vector<pair<long long, long long> > arr1[200005];
int main() {
  long long n, x, i, j, k, ans = 1e15;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> arr[i].l >> arr[i].r >> arr[i].cost;
    arr[i].dur = (arr[i].r - arr[i].l + 1);
    arr1[arr[i].dur].push_back(make_pair(arr[i].l, arr[i].cost));
  }
  for (i = 1; i <= 200000; i++)
    if (arr1[i].size()) sort(arr1[i].begin(), arr1[i].end());
  vector<long long>::iterator it;
  long long ncost;
  for (i = 1; i < x; i++) {
    if (arr1[i].size() == 0 || arr1[x - i].size() == 0) continue;
    tmp1.clear();
    tmp2.clear();
    for (j = 0; j < arr1[x - i].size(); j++) {
      tmp1.push_back(arr1[x - i][j].first);
      tmp2.push_back(3e9);
    }
    tmp2[j - 1] = arr1[x - i][j - 1].second;
    for (j = j - 2; j >= 0; j--)
      tmp2[j] = min(tmp2[j + 1], arr1[x - i][j].second);
    for (k = 0; k < arr1[i].size(); k++) {
      ncost = arr1[i][k].second;
      it = upper_bound(tmp1.begin(), tmp1.end(), i + arr1[i][k].first);
      if (it == tmp1.end())
        ncost = (1e15);
      else {
        ncost += (tmp2[it - tmp1.begin()]);
      }
      if (ncost < ans) ans = ncost;
    }
  }
  if (ans >= 1e15)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
