#include <bits/stdc++.h>
using namespace std;
const long long lp = 998244353;
int n;
long long p, q;
vector<int> val;
long long pow(long long x, long long p) {
  if (p == 1) return x;
  long long hf = pow(x, p / 2);
  if (p % 2) return ((hf * hf) % lp) * x % lp;
  return (hf * hf) % lp;
}
long long inv(long long x) { return pow(x, lp - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  val = vector<int>(n + 1);
  for (int i = 1; i <= n; i++) cin >> val[i];
  val[0] = 0;
  sort(val.begin() + 1, val.end(), greater<int>());
  for (int i = 1; i <= n; i++) val[i] = (val[i - 1] + val[i]) % lp;
  int seg, fin, idx, times;
  long long q = inv(n);
  for (int i = 1; i <= n; i++) {
    seg = min(i, n - i);
    idx = i;
    p = 0;
    times = -1;
    while (idx < n) {
      times++;
      if (idx + seg <= n) {
        long long add =
            (long long)times * ((val[idx + seg] - val[idx] + lp) % lp) % lp;
        p = (p + add) % lp;
        idx += seg;
      } else {
        long long add = (long long)times * ((val[n] - val[idx] + lp) % lp) % lp;
        p = (p + add) % lp;
        idx = n;
      }
    }
    p = (p + val[n] - val[i]) % lp;
    cout << (p * q) % lp << " ";
  }
  cout << endl;
  return 0;
}
