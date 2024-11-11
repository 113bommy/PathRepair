#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int isCanPar(long long a[], int n) {
  map<long long, int> mp;
  for (int i = 0; i < n; ++i) mp[a[i]]++;
  int cnt = 0;
  for (auto i = mp.begin(); i != mp.end(); ++i)
    if (i->second % 2 == 1) cnt++;
  if (n % 2 == 0) return cnt == 0;
  return cnt <= 1;
}
int findM(long long a[], int n) {
  for (int i = 0; i < n; ++i)
    if (a[i] != a[n - 1 - i]) return i;
  return n;
}
int type1(long long *a, int n) {
  int mid = (n - 1) / 2;
  int p = mid;
  while (a[p] == a[n - 1 - p]) p--;
  map<int, int> mp;
  for (int i = 0; i <= p; ++i) {
    mp[a[i]]++;
    mp[a[n - 1 - i]]--;
  }
  for (auto it = mp.begin(); it != mp.end(); ++it)
    if (it->second != 0) return -1;
  return p;
}
pair<int, int> type2(long long *a, int n) {
  int sf, pf;
  map<long long, int> mp1;
  for (int i = 0; i < n; ++i) mp1[a[i]]++;
  int cntG = 0;
  map<long long, int> mps;
  set<long long> sts;
  for (int i = 0; i < n; ++i) {
    mps[a[i]]++;
    if (sts.find(a[i]) == sts.end() && 2 * mps[a[i]] >= mp1[a[i]]) {
      sts.insert(a[i]);
      cntG++;
    }
    if (cntG == mp1.size()) {
      sf = i + 1;
      break;
    }
  }
  mps.clear();
  sts.clear();
  cntG = 0;
  for (int i = n - 1; i >= 0; --i) {
    mps[a[i]]++;
    if (sts.find(a[i]) == sts.end() && 2 * mps[a[i]] >= mp1[a[i]]) {
      sts.insert(a[i]);
      cntG++;
    }
    if (cntG == mp1.size()) {
      pf = n - i;
      break;
    }
  }
  return {sf, pf};
}
pair<int, int> findSf(long long *a, int n) {
  int v = type1(a, n);
  if (v != -1) {
    return {v + 1, v + 1};
  }
  return type2(a, n);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (!isCanPar(a, n)) {
    cout << 0;
    return 0;
  }
  long long m = findM(a, n);
  if (m == n) {
    cout << n + n * (n - 1) / 2;
    return 0;
  }
  pair<int, int> sf = findSf(a + m, n - 2 * m);
  long long re =
      (m + 1) * (long long)(2 * n - 3 * m - sf.first - sf.second + 1);
  cout << re;
}
