#include <bits/stdc++.h>
const int mod = 1e9 + 9;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int root = 1e6 + 7;
using namespace std;
long long t, n;
string a;
int v[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a;
  for (int i = 0; i < a.size() - 1; i++) {
    int t1 = a[i] - '0';
    int t2 = a[i + 1] - '0';
    if (t1 + t2 == 9) {
      v[i] = 1;
    }
  }
  long long ans = 1, tmp = 0;
  for (int i = 1; i < a.size() - 1; i++) {
    if (v[i])
      tmp++;
    else if (tmp % 2 == 0 && tmp != 0) {
      ans *= ((tmp / 2) + 1);
      tmp = 0;
    } else {
      tmp = 0;
    }
  }
  if (tmp % 2 == 0 && tmp != 0) ans *= (tmp / 2 + 1);
  cout << ans << endl;
  return 0;
}
