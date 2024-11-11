#include <bits/stdc++.h>
using namespace std;
long long int n, k, a[100014];
vector<long long int> res;
long long int get_diff(int i, long long int x) {
  return -3 * x * x + 3 * x + a[i] - 1;
}
long long int eval(long long int minval, bool compres = false) {
  long long int totk = 0;
  for (int i = (0); i < (n); i++) {
    long long int low, high, mid, resk;
    low = 0;
    high = a[i];
    resk = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      if (get_diff(i, mid) >= minval) {
        low = mid + 1;
        resk = max(resk, mid);
      } else
        high = mid - 1;
    }
    if (compres) res.push_back(resk);
    totk += resk;
  }
  return totk;
}
int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = (0); i < (n); i++) scanf("%lld", &a[i]);
  long long int low, high, mid, resval;
  low = -4000000000000000007LL;
  high = 4000000000000000007LL;
  resval = -4000000000000000007LL;
  while (low <= high) {
    mid = (low + high) / 2;
    if (eval(mid) >= k) {
      low = mid + 1;
      resval = max(resval, mid);
    } else
      high = mid - 1;
  }
  long long int used = eval(resval, true);
  for (int i = (0); i < (res.size()); i++)
    if (res[i] && get_diff(i, res[i]) == resval) {
      if (used > k) {
        --used;
        --res[i];
      }
    }
  for (int i = (0); i < (res.size()); i++)
    printf("%lld%c", res[i], " \n"[i == res.size() - 1]);
  return 0;
}
