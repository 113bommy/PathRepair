#include <bits/stdc++.h>
using namespace std;
bool query(long long a, long long b, long long c) {
  cout << "? " << a << " " << b << " " << c << endl;
  string s;
  cin >> s;
  if (s[0] == 'Y') return true;
  return false;
}
long long n, k, x, y, cnt, h, cur = 1;
vector<long long> v;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  while (cnt < n) {
    cnt += cur;
    h++;
    cur *= k;
  }
  long long lft = 60 * n - (h * 2) * (h * 2);
  srand(time(NULL));
  for (long long lp = 1; lp <= lft / (n - 2); lp++) {
    x = 0, y = 0;
    while (x == y) {
      x = rand() % n + 1;
      y = rand() % n + 1;
    }
    v.clear();
    for (long long i = 1; i <= n; i++)
      if (i != x && i != y) {
        if (query(x, i, y)) v.push_back(i);
      }
    if ((long long)v.size() == 2 * h - 3) break;
  }
  for (auto a : v) {
    long long cnt = 0;
    for (auto b : v)
      if (b != a) cnt += query(a, b, x);
    if (cnt == h - 2) {
      cout << "! " << a << endl;
      return 0;
    }
  }
}
