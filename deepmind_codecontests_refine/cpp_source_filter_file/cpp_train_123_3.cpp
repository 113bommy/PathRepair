#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
long long int cnt = 0;
void dfs(long long int x, vector<long long int> arr[], bool visit[],
         long long int val[], long long int xyz, bool freq1[], bool freq2[]) {
  visit[x] = true;
  cnt++;
  val[x] = xyz;
  if (freq1[x] == 1) {
    freq1[val[x]] = 1;
  }
  if (freq2[x] == 1) {
    freq2[val[x]] = 1;
  }
  for (auto i : arr[x]) {
    if (visit[i] == 0) dfs(i, arr, visit, val, xyz, freq1, freq2);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, a, b;
    cin >> n >> m >> a >> b;
    cnt = 0;
    vector<long long int> arr[n + 2], brr[n + 3], crr[3];
    vector<pair<long long int, long long int>> err;
    bool freq1[500004] = {0}, freq2[500004] = {0};
    for (long long int i = 0; i < m; i++) {
      long long int x, y;
      cin >> x >> y;
      arr[x].push_back(y);
      arr[y].push_back(x);
      if (x != a && x != b && y != a && y != b) {
        brr[x].push_back(y);
        brr[y].push_back(x);
      }
      if (x == a && y != b) {
        freq1[y] = true;
      }
      if (y == a && x != b) {
        freq1[x] = true;
      }
      if (x == b && y != a) {
        freq2[y] = true;
      }
      if (y == b && x != a) {
        freq2[x] = true;
      }
    }
    bool visit[200004] = {0};
    long long int val[200004];
    long long int xyz = 500000;
    long long int size[700003] = {0};
    vector<long long int> frr, grr, hrr;
    long long int sum = 0;
    for (long long int i = 1; i <= n; i++) {
      if (visit[i] == 0 && i != a && i != b) {
        cnt = 0;
        val[i] = xyz;
        dfs(i, brr, visit, val, xyz, freq1, freq2);
        xyz++;
        size[val[i]] = cnt;
        err.push_back(make_pair(cnt, val[i]));
        sum += cnt;
      }
    }
    long long int ct = 0;
    long long int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (long long int i = 0; i < err.size(); i++) {
      ct += err[i].first;
      long long int k = sum - ct;
      sum4 += err[i].first * k;
      if (freq1[err[i].second] == 1) {
        sum1 += err[i].first;
        frr.push_back(err[i].first);
      }
      if (freq2[err[i].second] == 1) {
        sum2 += err[i].first;
        grr.push_back(err[i].first);
      }
      if (freq1[err[i].second] == 1 && freq2[err[i].second] == 1) {
        sum3 += err[i].first;
        hrr.push_back(err[i].first);
      }
    }
    ct = 0;
    long long int sum5 = 0, sum6 = 0, sum7 = 0;
    for (long long int i = 0; i < grr.size(); i++) {
      ct += grr[i];
      long long int k = sum2 - ct;
      sum5 += grr[i] * k;
    }
    ct = 0;
    for (long long int i = 0; i < hrr.size(); i++) {
      ct += hrr[i];
      long long int k = sum3 - ct;
      sum6 += hrr[i] * k;
    }
    ct = 0;
    for (long long int i = 0; i < frr.size(); i++) {
      ct += frr[i];
      long long int k = sum1 - ct;
      sum7 += frr[i] * k;
    }
    cout << sum4 - sum5 - sum7 + sum6 << "\n";
  }
}
