#include <bits/stdc++.h>
using namespace std;
long long good[100005], bad[100005];
signed main() {
  string start, end;
  cin >> start >> end;
  long long x = 0, y;
  for (long long i = 0; i < start.size() - 1; i++) {
    string a = start.substr(0, i + 1),
           b = start.substr(i + 1, start.size() - i - 1);
    string s = b;
    s += a;
    if (s == end) x++;
  }
  y = start.size() - x;
  if (start == end) {
    good[0] = 1;
    bad[0] = 0;
  } else {
    good[0] = 0;
    bad[0] = 1;
  }
  long long k;
  cin >> k;
  for (long long i = 1; i <= k; i++) {
    good[i] = good[i - 1] * (x - 1) + bad[i - 1] * x;
    good[i] %= (long long)1e9 + 7;
    bad[i] = good[i - 1] * y + bad[i - 1] * (y - 1);
    bad[i] %= (long long)1e9 + 7;
  }
  cout << good[k] << endl;
  return 0;
}
