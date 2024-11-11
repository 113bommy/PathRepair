#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long n, m, p, mod = 1e9 + 7, sz, d1[N], d2[N], k, mpp[N], l, r, pw[N],
                   mp[N], ans, cnt[N][30], nt[N];
string s[N];
long long ss, le;
void go(int le, int ri) {
  for (int c = le; c <= ri; c++) {
    mpp[c - le + 1] = mp[c];
  }
  sz = ri - le + 1;
  l = 0;
  r = 0;
  for (int c = 1; c <= sz; c++) {
    if (c > r) {
      k = 1;
    } else {
      k = min(d1[l + (r - c)], r - c + 1);
    }
    while (c - k >= 1 && c + k <= sz && mpp[c - k] == mpp[c + k]) {
      k++;
    }
    d1[c] = k;
    if (c + k - 1 > r) {
      l = c - k + 1;
      r = c + k - 1;
    }
  }
  l = 0;
  r = 0;
  for (int c = 1; c <= sz; c++) {
    if (c > r) {
      k = 0;
    } else {
      k = min(d2[l + (r - c) + 1], r - c + 1);
    }
    while (c - k - 1 >= 1 && c + k <= sz && mpp[c - k - 1] == mpp[c + k]) {
      k++;
    }
    d2[c] = k;
    if (c + k >= r) {
      l = c - k;
      r = c + k - 1;
    }
  }
  for (int c = 1; c <= sz; c++) {
    ans += d1[c];
    ans += d2[c];
  }
}
int main() {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "@" + s[i];
  }
  p = 37;
  pw[0] = 1;
  for (int i = 1; i <= 30; i++) {
    pw[i] = pw[i - 1] * p;
    pw[i] %= mod;
  }
  for (int i = 1; i <= m; i++) {
    for (int r = 1; r <= n; r++) {
      mp[r] = 0;
      for (int jj = 1; jj <= 26; jj++) {
        cnt[r][jj] = 0;
      }
    }
    for (int j = i; j <= m; j++) {
      for (int r = 1; r <= n; r++) {
        nt[r] = 0;
        sz = j - i;
        cnt[r][int(s[r][j] - 'a' + 1)]++;
        mp[r] += pw[int(s[r][j] - 'a')];
        mp[r] %= mod;
      }
      for (int r = 1; r <= n; r++) {
        ss = 0;
        for (int jj = 1; jj <= 26; jj++) {
          if (cnt[r][jj] % 2 == 1) ss++;
          if (ss > 1) break;
        }
        if (ss > 1) nt[r] = 1;
      }
      nt[n + 1] = 1;
      le = 1;
      long long ans1 = ans;
      for (int w = 1; w <= n + 1; w++) {
        if (nt[w]) {
          if (le <= w - 1) {
            go(le, w - 1);
          }
          le = w + 1;
        }
      }
    }
  }
  cout << ans << endl;
}
