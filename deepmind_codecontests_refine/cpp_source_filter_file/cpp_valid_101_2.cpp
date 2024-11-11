#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b = b / 2;
  }
  return ans;
}
bool compare(pair<long long int, long long int>& a,
             pair<long long int, long long int>& b) {
  if (a.second == b.second)
    return a.first < b.second;
  else
    return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int mod = 998244353;
    long long int n, m, k, a;
    cin >> n >> m >> k;
    vector<pair<long long int, long long int> > arr(k);
    set<long long int> myset1, myset2;
    for (int i = 0; i < n; i++) {
      cin >> a;
      myset1.insert(a);
    }
    myset1.insert(1000000);
    for (int i = 0; i < m; i++) {
      cin >> a;
      myset2.insert(a);
    }
    myset2.insert(1000000);
    for (int i = 0; i < k; i++) {
      cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    long long int ans = 0, cur = 0;
    for (auto val : myset1) {
      map<long long int, long long int> mymap;
      while (cur < k && arr[cur].first < val) {
        mymap[arr[cur].second]++;
        cur++;
      }
      while (cur < k && arr[cur].first == val) {
        cur++;
      }
      long long int sum = 0, temp = 0;
      for (auto l : mymap) {
        sum += l.second;
        temp += (l.second * (l.second - 1)) / 2;
      }
      ans += ((sum * (sum - 1)) / 2 - temp);
    }
    cur = 0;
    sort(arr.begin(), arr.end(), compare);
    for (auto val : myset2) {
      map<long long int, long long int> mymap;
      while (cur < k && arr[cur].second < val) {
        mymap[arr[cur].first]++;
        cur++;
      }
      while (cur < k && arr[cur].second == val) {
        cur++;
      }
      long long int sum = 0, temp = 0;
      for (auto l : mymap) {
        sum += l.second;
        temp += (l.second * (l.second - 1)) / 2;
      }
      ans += ((sum * (sum - 1)) / 2 - temp);
    }
    cout << ans << endl;
  }
}
