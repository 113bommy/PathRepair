#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
void Draganov47(string click) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long mul(long long a, long long b, const long long M) {
  return (a * b) % M;
}
long long add(long long a, long long b, const long long M) {
  return (a + b >= M ? a + b - M : a + b);
}
void submit() {
  const long long M = 1e9 + 7;
  int m, n;
  cin >> m >> n;
  vector<vector<long long>> c(m + 1, vector<long long>(m + 1));
  vector<long long> b(m + 1);
  c[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1], M);
    }
  }
  b[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < i; j++) {
      b[i] = add(b[i], mul(c[i - 1][j], b[i - j - 1], M), M);
    }
  }
  vector<long long> a(m);
  for (int i = 0; i < n; i++) {
    long long k = (1ll << i);
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[j] += (s[j] - '1') * k;
    }
  }
  long long ans = 1;
  sort(a.begin(), a.end());
  for (int l = 0, r = 0; l < m; l = r) {
    while (r < m && a[l] == a[r]) {
      r++;
    }
    ans = mul(ans, b[r - l], M);
  }
  cout << ans;
}
int main() {
  Draganov47("vk.com/gotovseros");
  int T = 1, c = 0;
  while (T--) {
    submit();
  }
  return 0;
}
