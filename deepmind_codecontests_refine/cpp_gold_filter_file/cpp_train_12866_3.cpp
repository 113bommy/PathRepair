#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
long long step(long long a, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return step(a * a, n / 2);
  else
    return a * step(a, n - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> A, d;
  A.resize(n + 1);
  d.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> A[i];
  vector<int> tmp(n + 1, 10e6);
  for (int i = n; i >= 1; i--) {
    d[i] = tmp[A[i]];
    tmp[A[i]] = i;
  }
  set<pair<int, int>> cur;
  set<int> used;
  int ans = 0, last = 0;
  for (int i = 0; i <= n; i++) tmp[i] = 0;
  for (int i = 1; i <= n && used.size() < k; i++) {
    if (used.find(A[i]) == used.end()) {
      ans++;
      used.insert(A[i]);
      cur.insert(make_pair(-d[i], A[i]));
      tmp[A[i]] = -d[i];
    } else {
      cur.erase(cur.find(make_pair(tmp[A[i]], A[i])));
      cur.insert(make_pair(-d[i], A[i]));
      tmp[A[i]] = -d[i];
    }
    last = i;
  }
  for (int i = last + 1; i <= n; i++) {
    if (used.find(A[i]) != used.end()) {
      cur.erase(cur.find(make_pair(tmp[A[i]], A[i])));
      cur.insert(make_pair(-d[i], A[i]));
      tmp[A[i]] = -d[i];
    } else {
      pair<int, int> t = *cur.begin();
      cur.erase(cur.begin());
      used.erase(t.second);
      used.insert(A[i]);
      cur.insert(make_pair(-d[i], A[i]));
      tmp[A[i]] = -d[i];
      ans++;
    }
  }
  cout << ans;
  return 0;
}
