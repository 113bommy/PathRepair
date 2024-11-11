#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<long long, long long>& a, pair<long long, long long>& b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  vector<pair<long long, long long>> arr(n);
  for (int i = 0; i < n; i++) arr[i].first = a[i].first - a[i].second;
  for (int i = 0; i < n; i++) arr[i].second = a[i].second - a[i].first;
  long long ct = 0;
  vector<long long> v(n);
  sort(arr.begin(), arr.end(), comp);
  for (int i = 0; i < n; i++) v[i] = arr[i].second;
  for (int i = 0; i < n; i++) {
    long long k = arr[i].first;
    int ind = lower_bound(v.begin(), v.end(), k) - v.begin();
    if (ind - i - 1 >= 0) {
      ct += ind - i - 1;
    }
  }
  cout << ct << endl;
}
