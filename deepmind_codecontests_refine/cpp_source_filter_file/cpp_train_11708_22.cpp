#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
long long mod = 1000000007;
vector<long long> gr[200001];
vector<long long> grev[200001];
long long a[200005];
long long b[200005];
long long n, m;
set<long long> temp1;
set<long long> temp2;
set<long long> ans;
void go(long long i, long long taken, long long mask, long long bit) {
  if (n == bit) {
    if (taken == b[i]) temp1.insert(mask);
    return;
  }
  if (taken < b[i]) {
    go(i, taken + 1, mask | ((((a[i]) >> bit) & 1) << bit), bit + 1);
  }
  go(i, taken, mask | (((~(a[i]) >> bit) & 1) << bit), bit + 1);
}
void solve() {
  cin >> n >> m;
  for (long long i = int(0); i < int(m); i++) {
    bitset<35> x;
    cin >> x >> b[i];
    a[i] = x.to_ulong();
  }
  go(0, 0, 0, 0);
  ans = temp1;
  for (long long i = int(1); i < int(m); i++) {
    temp1.clear();
    go(i, 0, 0, 0);
    temp2.clear();
    for (long long x : ans) {
      if (temp1.find(x) != temp1.end()) temp2.insert(x);
    }
    ans = temp2;
  }
  cout << ((int)temp2.size()) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
