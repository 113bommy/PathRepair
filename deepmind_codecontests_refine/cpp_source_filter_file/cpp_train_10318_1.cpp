#include <bits/stdc++.h>
using namespace std;
inline void normal(long long &a) { a = (a + 1000000007) % 1000000007; }
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInv(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInv(b));
}
void km() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  map<long long, long long> mp;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]]++;
  }
  vector<char> ans(n);
  for (long long i = 0; i < n; i++) {
    ans[i] = 'C';
  }
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (mp[v[i]] == 1) {
      if (cnt % 2 == 0) {
        ans[i] = 'A';
        cnt++;
      } else {
        ans[i] = 'B';
        cnt++;
      }
    }
  }
  if (cnt % 2 == 1) {
    long long flag = 0;
    for (long long i = 0; i < n; i++) {
      if (mp[v[i]] > 2) {
        ans[v[i]] = 'B';
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "NO";
      return;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (ans[i] == 'C') ans[i] = 'A';
  }
  cout << "YES" << '\n';
  for (long long i = 0; i < n; i++) {
    cout << ans[i];
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start, end;
  start = clock();
  cout << fixed << setprecision(18);
  ;
  long long t;
  t = 1;
  while (t--) {
    km();
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
}
