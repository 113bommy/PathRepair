#include <bits/stdc++.h>
using namespace std;
int n;
long long r;
long long l[200005];
long long t[200005];
long long T;
void read() {
  int i;
  cin >> n >> r;
  for (i = 1; i <= n; i++) cin >> l[i];
  for (i = 1; i <= n; i++) cin >> t[i];
}
vector<long long> v;
long long k;
void solve() {
  int i;
  long long left = 0;
  long long br;
  long long j;
  for (i = 1; i <= n; i++) {
    if (t[i] < l[i]) {
      cout << -1 << endl;
      exit(0);
    }
    if (left >= l[i]) {
      T += l[i];
      left -= l[i];
      continue;
    }
    if (left > 0LL) {
      T += left;
      l[i] -= left;
      t[i] -= left;
      left = 0;
    }
    if (t[i] >= 2LL * l[i]) {
      T += 2LL * l[i];
      continue;
    }
    long long x = 2 * l[i] - t[i];
    br = x / r;
    if (br * r != x) br++;
    k += br;
    if (k <= 1LL * 100000) {
      for (j = 0; j < br; j++) {
        v.push_back(T + (l[i] - x) + j * r);
      }
    }
    left = br * r - x;
    T += t[i];
  }
  cout << k << endl;
  if (k <= 1LL * 100000) {
    for (i = 0; i < k; i++) cout << v[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  read();
  solve();
  return 0;
}
