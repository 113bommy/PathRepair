#include <bits/stdc++.h>
using namespace std;
void finish(long long num) {
  cout << num << endl;
  exit(0);
}
int main() {
  vector<long long> a(6);
  for (long long i = 0; i < 6; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long n;
  cin >> n;
  vector<long long> b(n);
  for (long long i = 0; i < n; i++) cin >> b[i];
  vector<pair<long long, long long> > arr;
  for (long long i = 0; i < 6; i++) {
    for (long long j = 0; j < n; j++) {
      arr.push_back({b[j] - a[i], j});
    }
  }
  sort(arr.begin(), arr.end());
  long long ans = (long long)10000000000000000;
  long long curans = 0;
  vector<long long> reached(n, 0);
  long long reachednum = 0;
  long long last = -1;
  while (reachednum < n) {
    last++;
    if (reached[arr[last].second] == 0) {
      reachednum++;
    }
    reached[arr[last].second]++;
  }
  long long start = 0;
  while (true) {
    if (last >= arr.size()) finish(ans);
    ans = min(ans, arr[last].first - arr[start].first);
    long long curj = arr[start].second;
    reached[curj]--;
    start++;
    while (reached[curj] == 0) {
      last++;
      if (last >= arr.size()) finish(ans);
      reached[arr[last].second]++;
    }
  }
  finish(ans);
}
