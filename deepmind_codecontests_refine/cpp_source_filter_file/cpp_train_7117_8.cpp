#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int n;
const long long int mod = 1000000007;
int a[100005];
int factor[1000], factor2[1000];
int pos[1000];
long long int mpow(long long int a, long long int k) {
  long long int res = 1;
  while (k) {
    if (k & 1) res = (res * a) % mod;
    a = a * a % mod;
    k >>= 1;
  }
  return res;
}
long long int getval(int cnt) {
  if (cnt == 0) return 0;
  long long int cur = 1;
  for (int j = 0; j < cnt; ++j) {
    int num = pos[j + 1] - pos[j];
    cur = (cur * mpow(j + 1, num)) % mod;
  }
  return cur;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  long long int res = 0;
  for (int i = 6; i >= 1; --i) {
    int cnt = 0, cnt2 = 0;
    for (int j = 1; j * j <= i; ++j)
      if (i % j == 0) {
        factor[cnt++] = j;
        if (j * j != i) factor2[cnt2++] = i / j;
      }
    for (int j = cnt2 - 1; j >= 0; --j) factor[cnt++] = factor2[j];
    for (int j = 0; j < cnt; ++j) {
      pos[j] = lower_bound(a, a + n, factor[j]) - a;
    }
    pos[cnt] = n;
    long long int tmp = getval(cnt);
    pos[cnt - 1] = n;
    tmp = (tmp - getval(cnt - 1) + mod) % mod;
    res = (res + tmp) % mod;
  }
  cout << res << endl;
  return 0;
}
