#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> add_pair(pair<long long, long long> a,
                                    pair<long long, long long> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
long long power(long long a, long long b) {
  long long res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, 1000000007 - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, m, n, tmp, mn, mx;
  string str, str2;
  cin >> t;
  while (t--) {
    cin >> str >> str2;
    n = str.length();
    m = str2.length();
    if (str < str2) {
      cout << str << '\n';
      continue;
    }
    for (i = (0); i < (n); i += (1)) {
      mn = i;
      for (j = (i + 1); j < (n); j += (1)) {
        if (str[j] <= str[mn]) mn = j;
      }
      string tmp = str;
      swap(tmp[i], tmp[mn]);
      if (tmp < str2) {
        str = tmp;
        break;
      }
    }
    if (str < str2)
      cout << "---\n";
    else
      cout << str << '\n';
  }
  return 0;
}
