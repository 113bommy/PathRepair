#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 2;
long long query0i[N];
long long queryi0[N];
long long query(long long i, long long j) {
  cout << "? " << i << " " << j << "\n";
  fflush(stdout);
  long long x;
  cin >> x;
  return x;
}
bool seen[N];
long long p[N];
long long b[N];
int main() {
  long long t, i, j;
  long long n;
  cin >> n;
  long long tmp = query(0, 0);
  query0i[0] = tmp;
  queryi0[0] = tmp;
  for (i = 1; i < n; i++) {
    query0i[i] = query(0, i);
  }
  for (i = 1; i < n; i++) queryi0[i] = query(i, 0);
  long long cnt = 0;
  vector<long long> myvec;
  long long pi;
  for (long long b0 = 0; b0 < n; b0++) {
    memset(seen, 0, sizeof(seen));
    for (pi = 0; pi < n; pi++) {
      long long tmp = queryi0[pi] ^ b0;
      if (tmp >= n) break;
      if (seen[tmp]) break;
      seen[tmp] = 1;
      p[pi] = tmp;
    }
    if (pi != n) continue;
    for (i = 0; i < n; i++) {
      b[p[i]] = i;
    }
    for (i = 0; i < n; i++) {
      if (p[0] ^ b[i] != query0i[i]) break;
    }
    if (i != n) continue;
    for (i = 0; i < n; i++) {
      if (p[i] ^ b[0] != queryi0[i]) break;
    }
    if (i != n) continue;
    cnt++;
    if (cnt == 1) {
      for (i = 0; i < n; i++) myvec.push_back(p[i]);
    }
  }
  cout << "!\n";
  cout << cnt << "\n";
  for (auto v : myvec) cout << v << " ";
}
