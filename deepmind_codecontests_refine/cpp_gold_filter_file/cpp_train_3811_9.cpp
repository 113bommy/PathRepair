#include <bits/stdc++.h>
using namespace std;
struct BIT {
  vector<long long> seg;
  void init() {
    for (long long i = 0; i <= 100007; i++) seg.push_back(0);
  }
  void add(long long i, long long k) {
    for (; i <= 100001; i += (i) & (-i)) seg[i] += k;
  }
  long long get(long long i) {
    long long s = 0;
    for (; i > 0; i -= (i) & (-i)) s += seg[i];
    return s;
  }
  long long get(long long l, long long r) { return get(r) - get(l); }
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  string s;
  long long q;
  cin >> s >> q;
  map<char, long long> A;
  A['A'] = 0;
  A['T'] = 1;
  A['G'] = 2;
  A['C'] = 3;
  BIT X[11][10][4];
  for (long long i = 1; i <= 10; i++)
    for (long long j = 0; j < i; j++)
      for (long long k = 0; k < 4; k++) X[i][j][k].init();
  for (long long i = 0; i < s.size(); i++) {
    for (long long a = 1; a <= 10; a++) {
      long long b = i % a;
      X[a][b][A[s[i]]].add(i + 1, 1);
    }
  }
  while (q--) {
    long long x;
    cin >> x;
    if (x == 1) {
      long long i;
      char c;
      cin >> i >> c;
      i--;
      long long aa = A[s[i]];
      long long B = A[c];
      for (long long a = 1; a <= 10; a++) {
        long long b = (i) % a;
        X[a][b][aa].add(i + 1, -1);
      }
      for (long long a = 1; a <= 10; a++) {
        long long b = (i) % a;
        X[a][b][B].add(i + 1, 1);
      }
      s[i] = c;
    }
    if (x == 2) {
      long long l, r;
      string e;
      cin >> l >> r >> e;
      long long a = e.length();
      long long ans = 0;
      l--;
      r--;
      for (int i = 0; i < a; i++) {
        int b = (l + i + a) % a;
        ans += X[a][b][A[e[i]]].get(l, r + 1);
      }
      cout << ans << "\n";
    }
  }
}
