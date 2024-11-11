#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const int iinf = 1 << 29;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long mrand(long long B) { return (unsigned long long)rng() % B; }
long long cross(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first * p2.second - p2.first * p1.second;
}
bool online(pair<long long, long long> a, pair<long long, long long> b,
            pair<long long, long long> c) {
  pair<long long, long long> p1{b.first - a.first, b.second - a.second};
  pair<long long, long long> p2{c.first - a.first, c.second - a.second};
  return cross(p1, p2) == 0;
}
void z_func(vector<int> &z, vector<int> &s, int n) {
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R - L] == s[R]) R++;
      z[i] = R - L;
      R--;
    } else {
      int k = i - L;
      if (z[k] < R - i + 1)
        z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R - L] == s[R]) R++;
        z[i] = R - L;
        R--;
      }
    }
  }
}
void work() {
  long long n, k, p;
  cin >> n >> k >> p;
  long long last, left = 0;
  if (k == 0) {
    last = n + 1LL;
  } else if (k == 1LL) {
    last = n;
  } else {
    if (n & 1LL) {
      if (k <= ((n >> 1) + 1LL)) {
        last = n - 1LL;
      } else {
        left = n - ((n >> 1) + 1LL);
        last = n - 2LL * left;
        --last;
      }
    } else {
      if (k <= (n >> 1)) {
        last = n;
      } else {
        left = n - (n >> 1);
        last = n - ((2LL * left) - 1LL);
        --last;
      }
    }
  }
  while (p--) {
    long long q;
    cin >> q;
    if (q >= last) {
      cout << "X";
      continue;
    }
    if ((n % 2LL == 0 && (k >= (n >> 1))) ||
        (n & 1LL && (k >= ((n >> 1) + 1LL)))) {
      if ((last - q) & 1LL) {
        cout << ".";
      } else {
        cout << "X";
      }
      continue;
    }
    if ((last - q) & 1LL) {
      cout << ".";
      continue;
    }
    left = n & 1LL ? k - 2LL : k - 1LL;
    if (((last - q) >> 1) <= left) {
      cout << "X";
    } else {
      cout << ".";
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  work();
  return 0;
}
