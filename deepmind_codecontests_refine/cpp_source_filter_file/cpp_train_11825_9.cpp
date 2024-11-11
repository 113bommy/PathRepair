#include <bits/stdc++.h>
using namespace std;
map<long long, long long> num, cnt;
inline long long store(int n) {
  if (n < 2) {
    num[n] = 1;
    cnt[n] = n;
  } else {
    num[n] = 2 * store(n / 2) + 1;
    cnt[n] = 2 * cnt[n / 2] + (n % 2);
  }
  return num[n];
}
long long find(long long n, long long l, long long r) {
  if (l == 1 && r == num[n]) return cnt[n];
  if (l > r) return 0;
  if (n < 2) return n;
  if (r <= num[n / 2]) {
    long long x = find(n / 2, l, r);
    return x;
  }
  if (l > num[n / 2] + 1) {
    long long x = find(n / 2, l - num[n / 2] - 1, r - num[n / 2] - 1);
    return x;
  }
  long long x =
      find(n / 2, l, num[n / 2]) + (n % 2) + find(n / 2, 1, r - num[n / 2] - 1);
  return x;
}
int main() {
  long long n, l, r, ans;
  cin >> n >> l >> r;
  store(n);
  ans = find(n, l, r);
  cout << ans << endl;
  return 0;
}
