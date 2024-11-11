#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  short negative = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  x *= negative;
}
long long quickpower(long long n, long long k) {
  long long ans = 1;
  while (k) {
    if (k % 2) {
      ans *= n;
      ans %= 1000000007;
    }
    n *= n;
    n %= 1000000007;
    k /= 2;
  }
  return ans;
}
string int_to_string(int n) {
  string s = "";
  while (n) {
    int now = n % 10;
    s += now + '0';
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
int string_to_int(string s) {
  int n = 0;
  for (int i = 0, _n = s.size(); i < s.size(); i++) {
    n *= 10;
    n += s[i] - '0';
  }
  return n;
}
bool p[1001000];
long long num[1001000];
vector<long long> plist;
long long ans[1001000];
int main() {
  ios::sync_with_stdio(0);
  for (long long i = 2; i <= 1000001; i++) {
    if (!p[i]) {
      plist.push_back(i);
      for (long long j = i + i; j <= 1000001; j += i) p[j] = 1;
    }
  }
  num[1] = 1;
  for (int i = (2), _b = (1000000); i <= _b; i++) {
    if (!p[i]) num[i]++;
    num[i] += num[i - 1];
  }
  memset(ans, -1, sizeof(ans));
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    if (ans[n] != -1) {
      printf("lld\n", ans[n]);
      continue;
    }
    long long l = 0;
    long long r = plist.size() + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (plist[mid] * plist[mid] <= n)
        l = mid + 1;
      else
        r = mid - 1;
    }
    ans[n] = num[n] - num[plist[l]] + 2;
    printf("%lld\n", ans[n]);
  }
  return 0;
}
