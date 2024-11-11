#include <bits/stdc++.h>
#pragma comment(linker, "/stack=64000000")
using namespace std;
const int MOD = 1000003;
int n, m;
vector<string> a;
vector<int> top, noname;
long long powmod(long long a, long long b) {
  long long res = 1, d = a;
  while (b)
    if (b & 1) {
      res = (res * d) % MOD;
      b--;
    } else {
      d = (d * d) % MOD;
      b /= 2;
    }
  return res % MOD;
}
int main() {
  cin >> n >> m;
  a.resize(n);
  getline(cin, a[0]);
  for (int i = 0; i < (int)n; i++) getline(cin, a[i]);
  top.assign(m, -1);
  noname.assign(n, -1);
  bool ok = true;
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)m; j++) {
      if (a[i][j] != '.') {
        int t = (a[i][j] == '1' || a[i][j] == '4') ^ (i & 1);
        if (top[j] == !t) ok = false;
        top[j] = t;
        int l = (a[i][j] == '1' || a[i][j] == '2') ^ (j & 1);
        if (noname[i] == !l) ok = false;
        noname[i] = l;
      }
    }
  if (!ok) {
    cout << 0 << endl;
    return 0;
  }
  int t_cnt = m - 1, l_cnt = n - 1;
  for (int j = (int)1; j < (int)m; j++)
    if (top[j] != -1) t_cnt--;
  for (int i = (int)1; i < (int)n; i++)
    if (noname[i] != -1) l_cnt--;
  long long res = 0;
  for (int p1 = 0; p1 < (int)2; p1++)
    for (int p2 = 0; p2 < (int)2; p2++) {
      if (noname[0] = !p1 || top[0] == !p2) continue;
      long long add = powmod(2, t_cnt);
      add = (add * powmod(2, l_cnt)) % MOD;
      res = (res + add) % MOD;
    }
  cout << res;
}
