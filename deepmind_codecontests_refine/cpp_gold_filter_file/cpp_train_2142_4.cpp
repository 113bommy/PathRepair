#include <bits/stdc++.h>
using namespace std;
template <class T, class T1>
int chkmin(T &x, const T1 &y) {
  return x > y ? x = y, 1 : 0;
}
template <class T, class T1>
int chkmax(T &x, const T1 &y) {
  return x < y ? x = y, 1 : 0;
}
long long MAXN = 9223372036854775807, mod = 998244353;
bool comp(pair<long long, pair<long long, long long>> &a,
          pair<long long, pair<long long, long long>> &b) {
  if (a.first == b.first) {
    return a.second.first < b.second.first;
  } else
    return a.first < b.first;
}
bool isprime(long long x) {
  if (x == 1) return false;
  if (x == 2 || x == 3 || x == 5) return true;
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  for (long long t = 0; t < T; t++) {
    long long n, k, a, b;
    cin >> n >> k >> a >> b;
    string ans = "";
    long long x = (n) / (k + 1);
    if (min(a, b) < x) {
      cout << "NO";
      return 0;
    }
    while (1) {
      if (a > b) {
        long long c = 0;
        while (a and c < k and a >= b) {
          a--;
          cout << 'G';
          c++;
        }
        c = 0;
        if (b and b < a) {
          cout << 'B';
          b--;
        }
        while (b and b >= a and c < k) {
          b--;
          cout << 'B';
          c++;
        }
      } else {
        long long c = 0;
        while (b and c < k and b >= a) {
          b--;
          cout << 'B';
          c++;
        }
        c = 0;
        if (a and a < b) {
          cout << 'G';
          a--;
        }
        while (a and a >= b and c < k) {
          a--;
          cout << 'G';
          c++;
        }
      }
      if (a == 0 and b == 0) break;
    }
  }
  return 0;
}
