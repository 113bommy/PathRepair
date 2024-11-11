#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int maxn = (int)3e5 + 5;
const double eps = 1e-9;
long long n, m, s[maxn], id[maxn], ans[maxn];
char d[maxn];
long long t, p;
bool cmp(int i, int j) { return s[i] < s[j]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> d[i];
    id[i] = i;
    s[i]--;
  }
  sort(id, id + n, cmp);
  for (int i = 0; i < n; i++) {
    if (d[i] == 'R') {
      p += (t / m) % n;
      if (t % m + s[i] >= m) p++;
      s[i] = (s[i] + (t % m)) % m;
    } else {
      p -= (t / m) % n;
      if (s[i] - t % m < 0) p--;
      s[i] = (s[i] - (t % m) + m) % m;
    }
    p %= n;
    p = (p + n) % n;
  }
  sort(s, s + n);
  for (int i = 0; i < n; i++) ans[id[i]] = s[(i + p) % n];
  for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
}
