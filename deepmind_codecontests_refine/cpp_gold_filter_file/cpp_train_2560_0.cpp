#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<pair<long long, long long>, long long> &a,
               const pair<pair<long long, long long>, long long> &b) {
  return (a.first.first > b.first.first);
}
int main() {
  unordered_map<long long, long long> mp;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j, k, n, sum = 0, x, a[200002] = {0}, b[200002] = {0};
  string s, s1, s2, s3;
  cin >> n >> k;
  vector<pair<pair<long long, long long>, long long>> v;
  for (i = 0; i < n; i++) {
    cin >> b[i];
    x = b[i];
    if (x % 2)
      a[i] = (x / 2) + 1;
    else
      a[i] = x / 2;
    v.push_back(make_pair(make_pair(b[i], a[i]), i));
  }
  sort(v.begin(), v.end(), sortbysec);
  for (i = 0; i < n; i++) {
    sum = sum + a[i];
  }
  if (sum > k) {
    cout << "-1";
    return 0;
  } else {
    long long rem = k - sum;
    for (i = 0; i < n; i++) {
      x = v[i].first.first - v[i].first.second;
      if (rem > x) {
        v[i].first.second += x;
        rem = rem - x;
        ;
      } else {
        v[i].first.second += rem;
        break;
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (v[j].second == i) {
          cout << v[j].first.second << ' ';
          break;
        }
      }
    }
  }
}
