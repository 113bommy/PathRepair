#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
long long md = 1000000007;
using namespace std;
template <typename T>
T pw(T a, T b) {
  T c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m), b /= 2;
  }
  return c;
}
template <typename T>
T ceel(T a, T b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
template <typename T>
T my_log(T n, T b) {
  T i = 1, ans = 0;
  while (1) {
    if (i > n) {
      ans--;
      break;
    }
    if (i == n) break;
    i *= b, ans++;
  }
  return ans;
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long inverse(long long i) {
  if (i == 1) return 1;
  return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int Query(int c, int d) {
  cout << "? " << c << " " << d << "\n";
  cout.flush();
  int f;
  cin >> f;
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<int> a(30), b(30);
  int big, q1 = 0, q2 = 0;
  big = Query(0, 0);
  int pwe[30];
  pwe[0] = 1;
  for (int i = 1; i < 30; i++) pwe[i] = 2 * pwe[i - 1];
  for (int i = 29; i >= 0; i--) {
    int e, r = Query(q1 + (1 << i), q2 + (1 << i));
    if (big >= 0)
      e = Query(q1, q2 + (1 << i));
    else
      e = Query(q1 + (1 << i), q2);
    if (big == 0) {
      if (e > 0) a[i] = b[i] = 1, q1 += pwe[i], q2 += pwe[i];
      continue;
    } else if (big > 0) {
      if (r < 0) {
        a[i] = 1, q1 += pwe[i];
        big = e;
      } else {
        if (e > 0) a[i] = b[i] = 1, big = r, q1 += pwe[i], q2 += pwe[i];
      }
    } else {
      if (r > 0) {
        b[i] = 1, q2 += pwe[i];
        big = e;
      } else {
        if (e < 0) a[i] = b[i] = 1, big = r, q1 += pwe[i], q2 += pwe[i];
      }
    }
  }
  cout << "! " << q1 << " " << q2 << "\n";
  cout.flush();
}
