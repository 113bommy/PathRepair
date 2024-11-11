#include <bits/stdc++.h>
const int mod = 1000000007;
const int inf = 1000000009;
const long long INF = 1000000000000000009;
const long long big = 1000000000000000;
const long double eps = 0.000000000000000000001;
using namespace std;
int P[200005], H[200005], L[200005], R[200005], M[200005], M2[200005];
int O[200005];
bool check(int x, int y, int d) {
  if (x > y) swap(x, y);
  long long h1 = H[x + d - 1] - H[x - 1] + mod;
  h1 *= P[y - x];
  long long h2 = H[y + d - 1] - H[y - 1] + mod;
  h1 %= mod, h2 %= mod;
  if (h1 == h2) return 1;
  return 0;
}
string s = "#";
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  int echo = n;
  string napis;
  cin >> napis;
  napis = "#" + napis;
  for (int i = 2; i <= n; i++) {
    if (napis[i] == '1' && napis[i - 1] == '1' && !O[i - 1])
      O[i] = 2, O[i - 1] = 1;
  }
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    M2[i] = cur + 1;
    if (!O[i]) s += napis[i], cur++;
    M[i] = cur;
  }
  int ile = 0;
  for (int i = 1; i <= n; i++) {
    if (napis[i] == '0')
      ile = 0;
    else
      ile++;
    L[i] = ile;
  }
  ile = 0;
  for (int i = n; i >= 1; i--) {
    if (napis[i] == '0')
      ile = 0;
    else
      ile++;
    R[i] = ile;
  }
  P[0] = 1;
  n = s.size() - 1;
  for (int i = 1; i <= n; i++) P[i] = ((long long)P[i - 1] * 31) % mod;
  for (int i = 1; i <= n; i++)
    H[i] = ((long long)P[i] * ((int)s[i] - '0') + H[i - 1]) % mod;
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int a, c, x;
    cin >> a >> c >> x;
    int b, d;
    b = a + x - 1, d = c + x - 1;
    if (L[a] >= b - a + 1 && L[c] >= d - c + 1) {
      cout << "YES\n";
      continue;
    }
    int a1 = M2[a], b1 = M[b], c1 = M2[c], d1 = M[d];
    bool z1 = 0, z2 = 0, z3 = 0, z4 = 0;
    if (O[a] == 2 && (min(R[a], b - a + 1) % 2 == 0)) a1++;
    if (O[c] == 2 && (min(R[c], d - c + 1) % 2 == 0)) c1++;
    if (O[a] == 2 && (min(R[a], b - a + 1) & 1)) z1 = 1;
    if (O[b] == 1 && (min(L[b], b - a + 1) & 1)) z2 = 1;
    if (O[c] == 2 && (min(R[c], d - c + 1) & 1)) z3 = 1;
    if (O[d] == 1 && (min(L[d], d - c + 1) & 1)) z4 = 1;
    if (z1 && z3) z1 = 0, z3 = 0;
    if (z2 && z4) z2 = 0, z4 = 0;
    if (a1 == 0 && b1 != 0) a1++;
    if (c1 == 0 && d1 != 0) c1++;
    if (z1 && z4 && (b1 < a1) && (d1 < c1)) {
      cout << "YES\n";
      continue;
    }
    if (z2 && z3 && (b1 < a1 && d1 < c1)) {
      cout << "YES\n";
      continue;
    }
    if (z1) {
      if (s[c1] != '1') {
        cout << "NO\n";
        continue;
      }
      c1++;
    }
    if (z2) {
      if (s[d1] != '1') {
        cout << "NO\n";
        continue;
      }
      d1--;
    }
    if (z3) {
      if (s[a1] != '1') {
        cout << "NO\n";
        continue;
      }
      a1++;
    }
    if (z4) {
      if (s[b1] != '1') {
        cout << "NO\n";
        continue;
      }
      b1--;
    }
    if (b1 - a1 != d1 - c1) {
      cout << "NO\n";
      continue;
    }
    if (echo == 1000 && i == 108) {
      cout << a1 << b1 << endl;
      return 0;
    }
    if (b1 < a1 || check(a1, c1, b1 - a1 + 1))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
