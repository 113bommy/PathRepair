#include <bits/stdc++.h>
using namespace std;
const int SIZE = 3e5 + 5;
const long long INF = 1e14 + 5;
const long long MOD = 1e9 + 7;
struct abc {
  int t;
  int p;
};
bool operator<(abc a, abc b) {
  int r1 = min(a.t, a.p) - min(a.t * 2, a.p);
  int r2 = min(b.t, b.p) - min(b.t * 2, b.p);
  return r1 < r2;
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
bool inRange(int n, int m, int n0, int m0) {
  return n0 > -1 && m0 > -1 && m0 < m && n0 < n;
}
bool cmp1(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
bool cmp2(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> v(n);
  vector<int> need(n);
  vector<bool> have(n, false);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    --v[i];
    need[v[i]] = i;
  }
  int ans = 0;
  int curr = 0;
  for (int i = 0; i < n; ++i) {
    if (!have[v[i]]) {
      if (curr == k) {
        int mx = -1;
        int book = -1;
        for (int z = 0; z < n; ++z) {
          if (!have[z]) continue;
          int cz = 0;
          for (int j = i + 1; j < n; ++j) {
            if (v[j] == z) {
              cz = j;
              break;
            }
          }
          if (cz > mx) {
            mx = cz;
            book = z;
          }
        }
        have[book] = false;
        --curr;
      }
      ++curr;
      have[v[i]] = true;
      ++ans;
    }
  }
  printf("%d", ans);
  return 0;
}
