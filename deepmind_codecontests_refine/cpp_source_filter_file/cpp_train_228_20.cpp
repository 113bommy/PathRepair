#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long base = 1e9 + 7;
const long long oo = 1e6 + 10;
const long long gh = 1e3 + 3;
const long long inf = 1e15 + 5;
long long n, m, k, q;
long long a[oo];
long long b[oo];
long long sum[oo];
string s;
char c[oo];
void input() {
  long long x, y, z;
  cin >> n >> m;
  cin >> s;
  for (long long i = 0; i <= 30; i++) b[i] = 0;
  for (long long i = 1; i <= m; i++) cin >> a[i];
  sort(a + 1, a + m + 1);
  long long j = 0;
  a[m + 1] = n;
  for (long long i = 1; i <= m + 1; i++) {
    while (j < a[i]) {
      long long t = s[j] - 'a';
      b[t]++;
      j++;
    }
    for (long long j = 0; j <= 26; j++) {
      sum[j] += b[j];
    }
  }
  for (long long j = 0; j < 26; j++) cout << sum[j] << " ";
  cout << endl;
}
void cre() {}
void solve() { cre(); }
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
  cin >> t;
  while (t--) {
    input();
    solve();
    ouput();
  }
}
