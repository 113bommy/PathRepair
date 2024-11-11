#include <bits/stdc++.h>
using namespace std;
long long n, s, l[200005];
pair<long long, long long> arr[200005];
bool valid(long long x) {
  long long cnt = 0;
  long long sum = 0, z;
  vector<long long> v;
  for (int i = 1; i <= n; i++) {
    if (arr[i].second < x) {
      sum += arr[i].first;
    } else if (arr[i].first >= x) {
      cnt++;
      sum += arr[i].first;
    } else {
      v.push_back(arr[i].first);
    }
  }
  int butuh = (n + 1) / 2;
  butuh -= cnt;
  butuh = max(0, butuh);
  if (butuh > v.size()) return false;
  int sz = v.size();
  for (int i = 0; i < sz - butuh; i++) {
    sum += arr[i].first;
  }
  sum += (x * butuh);
  return sum <= s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + n + 1);
    long long ki = 1, ka = 1e9;
    long long pos = ki;
    while (ki <= ka) {
      long long mid = (ki + ka) / 2;
      if (valid(mid)) {
        pos = mid;
        ki = mid + 1;
      } else
        ka = mid - 1;
    }
    cout << pos << endl;
  }
}
