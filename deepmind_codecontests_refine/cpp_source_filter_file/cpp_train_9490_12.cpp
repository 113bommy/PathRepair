#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ar[100005], tmp[100005];
long long lowest = 0;
pair<long long, long long> br[100005];
bool can(long long cur) {
  long long mn = 0;
  long long ind = m - 1;
  for (long long i = 0; i < m; i++) {
    if (br[i].first > cur) {
      ind = i - 1;
      break;
    }
  }
  vector<pair<long long, long long>> vp;
  map<long long, long long> mp;
  for (long long i = ind; i >= 0; i--) {
    if (mp[br[i].second]) {
      continue;
    }
    vp.push_back(br[i]);
    mp[br[i].second] = 1;
  }
  reverse(vp.begin(), vp.end());
  for (long long i = 0; i < vp.size(); i++) {
    if (tmp[vp[i].second] >= 1) {
      long long money = vp[i].first - mn;
      if (money >= tmp[vp[i].second]) {
        mn += tmp[vp[i].second];
        tmp[vp[i].second] = 0;
      } else {
        mn += money;
        tmp[vp[i].second] -= money;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    mn += tmp[i] * 2;
  }
  if (mn <= cur) {
    return true;
  } else {
    return false;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
    lowest += ar[i] * 2;
  }
  for (long long i = 0; i < m; i++) {
    cin >> br[i].first >> br[i].second;
    br[i].second--;
  }
  sort(br, br + m);
  long long l = lowest / 2, r = lowest;
  while (l < r) {
    for (long long i = 0; i < n; i++) {
      tmp[i] = ar[i];
    }
    long long mid = l + (r - l) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
