#include <bits/stdc++.h>
using namespace std;
int main() {
  ;
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int n, count = 0, value;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  vector<long long int> sum;
  map<long long int, vector<pair<long long int, long long int>>> hash;
  for (long long int i = 0; i < n; i++) {
    long long int temp = 0;
    for (long long int j = i; j < n; j++) {
      temp += arr[j];
      if (!hash.count(temp)) sum.push_back(temp);
      hash[temp].push_back(make_pair(j, i));
    }
  }
  vector<pair<long long int, long long int>> ans;
  for (long long int i = 0; i < sum.size(); i++) {
    sort(hash[sum[i]].begin(), hash[sum[i]].end());
    long long int tcount = 0;
    vector<pair<long long int, long long int>> temp;
    long long int index = 0;
    long long int min = -1;
    while (index < hash[sum[i]].size()) {
      if (hash[sum[i]][index].second > min) {
        min = hash[sum[i]][index].first;
        temp.push_back(
            make_pair(hash[sum[i]][index].second, hash[sum[i]][index].first));
        tcount++;
      }
      index++;
    }
    if (tcount > count) {
      count = tcount;
      value = sum[i];
      ans = temp;
    }
  }
  cout << count << "\n";
  for (long long int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
  return 0;
}
