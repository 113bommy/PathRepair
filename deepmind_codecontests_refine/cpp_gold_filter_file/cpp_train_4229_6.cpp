#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> v1, pair<long long, long long> v2) {
  return v1.second < v2.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long a[n], sum = 0;
  map<long long, long long> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    cnt[a[i]]++;
  }
  if (sum < k) {
    cout << "-1";
    return 0;
  }
  if (sum == k) {
    return 0;
  }
  long long sub = 0, left = n;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    if (it->first > sub) {
      long long rem = (it->first - sub) * left;
      if (k >= rem) {
        k -= rem;
        sub += (it->first - sub);
        left -= it->second;
      } else {
        long long pos = -1;
        sub += k / left;
        k %= left;
        for (int j = 0; j < n && k > 0; j++) {
          if (a[j] - sub > 0) {
            pos = j;
            a[j]--;
            k--;
          }
        }
        for (int j = pos + 1; j < pos + 1 + n; j++) {
          if (a[j % n] - sub > 0) {
            cout << j % n + 1 << ' ';
          }
        }
        return 0;
      }
    }
  }
  cout << "-1";
}
