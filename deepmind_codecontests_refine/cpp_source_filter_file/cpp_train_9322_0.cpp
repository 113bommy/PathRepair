#include <bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};
long long modpow(long long base, long long exp, long long mod) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
int n, q;
int price[100005], m[100005];
int bsrc(int find) {
  int beg = 0, end = n + 1, mid = (beg + end) / 2;
  while (beg <= end) {
    if (price[mid] > find && price[mid - 1] <= find) {
      return mid - 1;
    } else if (price[mid] > find) {
      end = mid - 1;
    } else {
      beg = mid + 1;
    }
    mid = (beg + end) / 2;
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  price[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> price[i];
  }
  price[n + 1] = 1000000007;
  sort(price, price + n);
  cin >> q;
  int mm;
  while (q--) {
    cin >> mm;
    int ans = bsrc(mm);
    if (ans == -1) ans = 0;
    cout << ans << endl;
  }
  return 0;
}
