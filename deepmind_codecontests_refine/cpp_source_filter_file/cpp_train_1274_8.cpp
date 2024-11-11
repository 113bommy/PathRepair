#include <bits/stdc++.h>
using namespace std;
long long int ctoi(char a) {
  long long int x = a - 48 - 49;
  return x;
}
string itos(long long int a) {
  string out_string;
  stringstream second;
  second << a;
  out_string = second.str();
  return out_string;
}
char itoc(long long int a) { return itos(a)[0]; }
long long int pow(long long int e, long long int x) {
  long long int ans = 1;
  while (x > 0) {
    if (x & 1) ans *= e;
    e *= e;
    x >>= 1;
  }
  return ans;
}
string bin(long long int x) {
  bitset<sizeof(1) * CHAR_BIT> bits(x);
  string b = bits.to_string();
  return b;
}
void solve() {
  long long int n, m, x, y;
  cin >> n;
  vector<long long int> a(n, 0);
  long long int ans = 0, ans2 = 0;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  bool f = 0;
  long long int temp = 0;
  for (long long int i = 0; i < n; i++) {
    if (f == 0 && a[i] > 0) {
      temp = max(temp, a[i]);
    } else if (f == 0 && a[i] < 0) {
      f = 1;
      ans += temp;
      temp = a[i];
    } else if (f == 1 && a[i] < 0) {
      temp = max(temp, a[i]);
    } else {
      f = 0;
      ans += temp;
      temp = a[i];
    }
  }
  ans += temp;
  temp = -1e9 + 10;
  f = 1;
  for (long long int i = 0; i < n; i++) {
    if (f == 0 && a[i] > 0) {
      temp = max(temp, a[i]);
    } else if (f == 0 && a[i] < 0) {
      f = 1;
      ans2 += temp;
      temp = a[i];
    } else if (f == 1 && a[i] < 0) {
      temp = max(temp, a[i]);
    } else {
      f = 0;
      ans2 += temp;
      temp = a[i];
    }
  }
  ans2 += temp;
  cout << max(ans, ans2) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
