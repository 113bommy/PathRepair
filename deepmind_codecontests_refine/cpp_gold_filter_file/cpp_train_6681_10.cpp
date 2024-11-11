#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O2")
#pragma GCC optimization("unrolled-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long base = 1e9 + 7;
const long long oo = 4e5 + 10;
const long long gh = 1e3 + 3;
const long long inf = 1e15 + 5;
long long n, m, k, q;
long long nextt[oo][27];
long long res[oo];
long long a[oo];
string st, s[oo];
long long Z[oo];
long long cnt[2][oo];
long long cur = 2, sq, len = 0;
void input() {
  cin >> st;
  len = st.length();
  cin >> n;
  sq = sqrt(len);
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
  }
}
long long tree[oo];
void hish(string s) {
  long long pos = 1;
  long long n = s.length();
  for (long long i = 0; i < n; i++) {
    long long A = s[i] - 'a';
    if (!nextt[pos][A]) nextt[pos][A] = ++cur;
    pos = nextt[pos][A];
  }
  tree[pos]++;
}
void calc(string s, long long x) {
  long long pos = 1;
  long long n = s.length();
  for (long long i = 0; i < n; i++) {
    char A = s[i] - 'a';
    pos = nextt[pos][A];
    cnt[0][x] += tree[pos];
    cnt[1][x + i] += tree[pos];
  }
}
void Zfunction(string a, long long d) {
  long long n = a.length();
  long long l = 0, r = 0;
  Z[0] = n;
  for (long long i = 1; i <= n; i++) {
    if (i > r) {
      l = r = i;
      while (a[r - l] == a[r]) r++;
      Z[i] = r - l;
      r--;
    } else {
      long long k = i - l;
      if (Z[k] < r - i + 1)
        Z[i] = Z[k];
      else {
        l = i;
        while (r < n && a[r] == a[r - l]) r++;
        Z[i] = r - l;
        r--;
      }
    }
    if (i >= d && Z[i] >= d) {
      cnt[0][i - d]++;
      cnt[1][i - 1]++;
    }
  }
}
void cre() {
  for (long long i = 1; i <= n; i++) {
    if (s[i].length() > sq)
      Zfunction(s[i] + st, s[i].length());
    else
      hish(s[i]);
  }
  string t;
  for (long long i = 0; i < len; i++) {
    t += st[i];
    if (t.length() > sq) t.erase(0, 1);
    if (t.length() == sq) {
      calc(t, i - t.length() + 1);
    }
  }
  while (t.length()) {
    t.erase(0, 1);
    calc(t, len - t.length());
  }
}
void solve() {
  cre();
  long long ans = 0;
  for (long long i = 0; i < len; i++) {
    ans += cnt[0][i] * cnt[1][i - 1];
  }
  cout << ans;
}
void ouput() {}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (ifstream("test.txt")) {
    freopen("test.txt", "r", stdin);
  } else if (ifstream(""
                      ".inp")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  long long t = 1;
  while (t--) {
    input();
    solve();
    ouput();
  }
}
