#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 100010;
int check(vector<int> &v) {
  int i, first, cur, j;
  for (i = 0; i < v.size(); i++) {
    first = j = 0;
    cur = v[i];
    while (j < 8) {
      if (cur == 1) {
        first = 1;
        break;
      }
      cur = v[cur];
      j++;
    }
    if (!first) return 0;
  }
  return 1;
}
int generator(vector<int> &v, int left, int k) {
  if (left == 0) return check(v);
  int i, ret = 0;
  for (i = 1; i <= k; i++) {
    v.push_back(i);
    ret += generator(v, left - 1, k);
    v.pop_back();
  }
  return ret;
}
long long modpow(long long a, long long b) {
  long long x = 1, y = a;
  while (b) {
    if (b % 2) x = (x * y) % mod;
    y = (y * y) % mod;
    b /= 2;
  }
  return x;
}
long long temp[] = {0, 1, 2, 9, 64, 625, 7776, 117649, 2092112};
int main() {
  int n, k;
  scanf("%d", &n), scanf("%d", &k);
  vector<int> v;
  long long ans = temp[k];
  ans = (ans * modpow(n - k, n - k)) % mod;
  cout << ans << "\n";
  return 0;
}
