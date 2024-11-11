#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  vector<int> pows(n);
  vector<long long> p(20);
  int i;
  map<long long, long long> hash[20];
  int mx = 0;
  int mi = 100;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    int al = arr[i];
    int cnt = 0;
    while (al) {
      al /= 10;
      cnt++;
    }
    pows[i] = cnt;
    int j;
    long long ex = 1;
    arr[i] %= k;
    for (j = 1; j < 12; j++) {
      ex = (ex * 10) % k;
      p[j] = ex;
      long long val = (arr[i] * ex) % k;
      hash[j][val]++;
    }
  }
  long long tot = 0;
  for (i = 0; i < n; i++) {
    long long val = (k - arr[i]) % k;
    long long vaal = (p[pows[i]] * arr[i]) % k;
    if (hash[pows[i]].find(val) != hash[pows[i]].end())
      tot += hash[pows[i]][val] - (vaal == val);
  }
  cout << tot << endl;
}
