#include <bits/stdc++.h>
using namespace std;
void OJ() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); }
long long fp(long long a, long long b, long long m = 1000000007) {
  a %= m;
  if (a == 0) return 0;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}
void solve() {
  OJ();
  long long t = 1;
  while (t--) {
    vector<long long> temp;
    long long n, k;
    cin >> n >> k;
    cout << "or " << 1 << " " << 2 << endl;
    long long o1;
    cin >> o1;
    cout << "or " << 2 << " " << 3 << endl;
    long long o2;
    cin >> o2;
    cout << "or " << 1 << " " << 3 << endl;
    long long o3;
    cin >> o3;
    cout << "and " << 1 << " " << 2 << endl;
    long long a1;
    cin >> a1;
    cout << "and " << 2 << " " << 3 << endl;
    long long a2;
    cin >> a2;
    cout << "and " << 1 << " " << 3 << endl;
    long long a3;
    cin >> a3;
    long long a = (a1 | a3);
    for (long long i = 30; i >= 0; i--) {
      long long v = (a >> i) & 1;
      if (v == 1) continue;
      long long v2 = (o1 >> i) & 1, v3 = (o3 >> i) & 1;
      if (v2 == 0 || v3 == 0) continue;
      long long v4 = (a2 >> i) & 1;
      if (v4 == 1) continue;
      a |= (1 << i);
    }
    long long b = (a1 | a2) | (a ^ o1);
    long long c = (a2 | a3) | (o3 ^ a);
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    for (long long i = 4; i <= n; i++) {
      cout << "or " << 1 << " " << i << endl;
      long long o;
      cin >> o;
      cout << "ans " << 1 << " " << i << endl;
      long long an;
      cin >> an;
      temp.push_back(an | (o ^ temp[0]));
    }
    sort(temp.begin(), temp.end());
    cout << "finish " << temp[k - 1] << endl;
    return;
  }
}
signed main() {
  solve();
  return 0;
}
