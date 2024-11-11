#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int MOD = 1000000007;
const long long INF = 1e18;
const int MX = 100001;
const double epsilon = 1e-12;
const int ds[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> jump;
int finds(int ci) {
  if (jump[ci] != ci) {
    jump[ci] = finds(jump[ci]);
  }
  return jump[ci];
}
void unions(int ci1, int ci2) {
  if (finds(ci1) != finds(ci2)) {
    jump[finds(ci1)] = finds(ci2);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v0(n + 5, 0);
  vector<int> v1(n + 5, 0);
  jump = vector<int>(n + 5, 0);
  for (int i = 0; i < n + 5; i++) {
    jump[i] = i;
  }
  string s1;
  cin >> s1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (s1[i] == '1' || s1[i] == '0') {
        v0[i] = s1[i] - '0';
        v1[i] = s1[i] - '0';
      } else {
        v0[i] = 0, v1[i] = 1;
      }
    } else {
      if (s1[i] == '1' || s1[i] == '0') {
        v0[i] += v0[i - 1] + s1[i] - '0';
        v1[i] += v1[i - 1] + s1[i] - '0';
      } else {
        v1[i] += v1[i - 1] + 1;
        v0[i] += v0[i - 1];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int total = 0;
    int ite = finds(0);
    while (ite + i <= n) {
      if ((ite ? v0[ite + i - 1] - v0[ite - 1] : v0[ite + i - 1]) == 0 ||
          (ite ? v1[ite + i - 1] - v1[ite - 1] : v1[ite + i - 1]) == i) {
        total++;
        ite += i;
        ite = finds(ite);
      } else {
        int ln = ite;
        ite = finds(finds(ite) + 1);
        unions(ln, ite);
      }
    }
    if (i == n) {
      printf("%d\n", total);
    } else {
      printf("%d ", total);
    }
  }
  return 0;
}
