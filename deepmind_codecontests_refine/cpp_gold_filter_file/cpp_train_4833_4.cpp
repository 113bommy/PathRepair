#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, pair<long long, long long>>> B;
vector<pair<long long, long long>> A;
long long n, m, S;
long long arr[200000 + 5];
bool valid(long long t) {
  int a = 0, s = 0;
  if (t < 0) return false;
  long long total = 0;
  set<pair<long long, long long>> sl;
  while (a < m) {
    while (s < n) {
      if (B[s].first < A[a].first) break;
      sl.insert({B[s].second.first, B[s].second.second});
      s++;
    }
    if (sl.empty()) return false;
    total += (*sl.begin()).first;
    pair<long long, long long> e = *sl.begin();
    sl.erase(sl.begin());
    if (total > S) return false;
    long long tmp = min(m, a + t);
    for (; a < tmp; a++) arr[A[a].second] = e.second;
  }
  return true;
}
int main() {
  scanf("%lld %lld %lld", &n, &m, &S);
  for (int i = 0; i < m; i++) {
    long long x;
    scanf("%lld", &x);
    A.push_back({x, i});
  }
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    B.push_back({x, {0, i}});
  }
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    B[i].second.first = x;
  }
  sort(A.begin(), A.end(), greater<pair<long long, long long>>());
  sort(B.begin(), B.end(),
       greater<pair<long long, pair<long long, long long>>>());
  long long start = 0, ende = m;
  long long ans = -1;
  while (start <= ende) {
    long long mid = (start + ende) / 2;
    if (valid(mid)) {
      ans = mid;
      ende = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  valid(ans);
  if (ans == -1) {
    cout << "NO";
  } else {
    cout << "YES\n";
    for (int i = 0; i < m; i++) cout << arr[i] + 1 << " ";
  }
  return 0;
}
