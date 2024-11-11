#include <bits/stdc++.h>
using namespace std;
const long long N = 3e6 + 100;
bool mark[N];
long long b[N], a[N];
vector<long long> v[N];
vector<long long> id[N];
void ok(long long x) {
  if (mark[x]) return;
  for (long long i = x; i < N; i += x) {
    mark[i] = true;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    id[a[i]].push_back(i);
  }
  for (long long i = 2; i < N; i++) {
    if (mark[i]) continue;
    for (long long j = i; j < N; j += i) {
      mark[j] = true;
      for (auto x : id[j]) {
        id[x].push_back(i);
      }
    }
  }
  long long p = 0;
  bool flag = false;
  memset(mark, 0, sizeof mark);
  for (long long i = 2; i < N; i++) {
    if (p >= n) break;
    if (mark[i]) continue;
    if (!flag && a[p] > i) {
      long long k;
      for (k = a[p]; k < N; k++) {
        if (!mark[k]) break;
      }
      long long k2 = k;
      if (k != a[p]) {
        flag = true;
        for (long long j = 2; j <= k; j++) {
          if (k % j != 0) continue;
          ok(j);
          while (k % j == 0) {
            k /= j;
          }
        }
      } else {
        for (auto x : id[p]) {
          ok(x);
        }
      }
      b[p++] = k2;
      i--;
      continue;
    }
    if (a[p] < i) flag = true;
    b[p++] = i;
    ok(i);
  }
  for (long long i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  return 0;
}
