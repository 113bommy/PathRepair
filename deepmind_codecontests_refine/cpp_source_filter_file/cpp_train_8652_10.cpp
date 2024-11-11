#include <bits/stdc++.h>
const int OO = 0x3f3f3f3f, mod = 1e9 + 7;
using namespace std;
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return ((x / gcd(x, y)) * y); }
void MR_VIRUS() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
void file() {}
long long nCr(long long n, long long r) {
  long long ans = 1;
  long long div = 1;
  if (n)
    for (long long i = r + 1; i <= n; i++) {
      ans = ans * i;
      ans /= div;
      div++;
    }
  return ans;
}
long long str_to_long(string s) {
  reverse(((s).begin()), ((s).end()));
  long long num = 0;
  while (!s.empty()) {
    num *= 10;
    num += (long long)(s.back() - '0');
    s.pop_back();
  }
  return num;
}
bool prime(long long n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long fastpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res *= a;
    b /= 2, a *= a;
  }
  return res;
}
long long n, k, sum;
map<long long, long long> mp;
bool ok(long long mid) {
  sum = 0;
  for (auto i : mp) {
    sum += i.second / mid;
  }
  return sum >= k;
}
int main() {
  MR_VIRUS();
  file();
  int TS = 1;
  while (TS--) {
    cin >> n >> k;
    int l = 1, r = n, x, mid, ans;
    for (int i = 0; i < n; i++) {
      cin >> x;
      mp[x]++;
    }
    while (l <= r) {
      mid = (l + r) / 2;
      if (ok(mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    for (auto& i : mp) {
      while (i.second >= ans && k) {
        cout << i.first << " ";
        k--;
        i.second--;
      }
    }
  }
}
