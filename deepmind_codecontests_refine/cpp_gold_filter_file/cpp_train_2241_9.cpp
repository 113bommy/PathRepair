#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, n, cnt[30], ans[105][105];
void set_it(long long &i, long long &j, long long &dir) {
  if (dir) {
    if (j < a + c - 1 && ans[i][j + 1] != 0)
      j++;
    else
      i++, dir = 0;
  } else {
    if (j > 0 && ans[i][j - 1] != 0)
      j--;
    else
      i++, dir = 1;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> c >> d >> n;
  for (long long i = 0; i < n; i++) cin >> cnt[i];
  memset(ans, -1, sizeof(ans));
  if (b > d) {
    for (long long i = d; i < b; i++) {
      for (long long j = a; j < a + c; j++) ans[i][j] = 0;
    }
  } else {
    for (long long i = b; i < d; i++) {
      for (long long j = 0; j < a; j++) ans[i][j] = 0;
    }
  }
  long long x = 0, y, di;
  if ((b > d && d % 2 == 1) || (b < d && b % 2 == 0))
    y = a + c - 1, di = 0;
  else
    y = 0, di = 1;
  for (long long i = 0; i < n; i++) {
    long long tmp = 0;
    pair<pair<long long, long long>, long long> nex;
    while (tmp < cnt[i]) {
      ans[x][y] = i + 1;
      set_it(x, y, di);
      tmp++;
    }
  }
  cout << "YES\n";
  for (long long i = 0; i < max(b, d); i++) {
    for (long long j = 0; j < a + c; j++) {
      if (ans[i][j])
        cout << (char)('a' + ans[i][j] - 1);
      else
        cout << '.';
    }
    cout << endl;
  }
  return 0;
}
