#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int isPrime(long long int n) {
  long long int p = (long long int)sqrt(n);
  for (long long int i = (2); i <= (p); i += (1))
    if (n % i == 0) return 0;
  return 1;
}
long long int pows(long long int b, long long int e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long int a = pow(b, e / 2);
    return a * a;
  } else {
    long long int a = pow(b, e / 2);
    return b * a * a;
  }
}
long long int powm(long long int x, long long int y,
                   long long int m = 1000000007) {
  x = x % m;
  long long int res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long int modInverse(long long int a, long long int m = 1000000007) {
  return powm(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, i, j, k, x, y, z, f, p, q, g, l, r, w, h,
      count = 0, count1 = 0, prod = 1, a, b, c, d, index, x1, x2, diff, sum = 0,
      sum1 = 0, sum2 = 0, flag = 0, flag1 = 0, flag2 = 0;
  string s, s1, s3;
  long long int ar[100005] = {0};
  cin >> n >> k;
  set<pair<long long int, long long int>> st;
  for (i = 0; i < k; i++) {
    cin >> x;
    st.insert({x, x});
    ar[x] = 1;
    if (ar[x - 1]) {
      st.insert({x - 1, x});
    }
    if (ar[x + 1]) {
      st.insert({x + 1, x});
    }
  }
  cout << 3 * n - 2 - st.size();
}
