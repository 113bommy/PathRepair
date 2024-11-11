#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
using namespace std;
long long maxx, minn;
int n, m;
int q;
long long a[110000], b[110000];
set<long long> values;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < (n); i++) cin >> a[i];
  for (int i = 0; i < (m); i++) cin >> b[i];
  long long cur = 0;
  for (int i = m - 1; i >= m - n; i--) {
    cur = -cur - b[i];
  }
  for (int i = m - n - 1; i >= 0; i--) {
    values.insert(cur);
    if (n % 2 == 1)
      cur += b[i + n];
    else
      cur -= b[i + n];
    cur = -cur - b[i];
  }
  values.insert(cur);
  long long base = 0;
  for (int i = 0; i < (n); i++) {
    if (i % 2 == 0)
      base += a[i];
    else
      base -= a[i];
  }
  {
    long long curAns = 1E18;
    set<long long>::iterator it = values.lower_bound(-base);
    if (it != values.end()) {
      curAns = min(curAns, abs(*it + base));
    }
    if (it != values.begin()) {
      it--;
      curAns = min(curAns, abs(*it + base));
    }
    cout << curAns << "\n";
  }
  for (int i = 0; i < (q); i++) {
    int l, r, x;
    cin >> l >> r >> x;
    if ((l - r + 1) % 2 == 1) {
      if (l % 2 == 1)
        base += x;
      else
        base -= x;
    }
    long long curAns = 1E18;
    set<long long>::iterator it = values.lower_bound(-base);
    if (it != values.end()) {
      curAns = min(curAns, abs(*it + base));
    }
    if (it != values.begin()) {
      it--;
      curAns = min(curAns, abs(*it + base));
    }
    cout << curAns << "\n";
  }
  return 0;
}
