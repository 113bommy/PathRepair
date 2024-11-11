#include <bits/stdc++.h>
using namespace std;
const long long k = 1e4, M = 10004205361450474;
map<pair<long long, long long>, long long> mp;
long long dp(long long n, long long l, long long run) {
  if (run && 0) {
    cout << "DDD " << n << " " << l << '\n';
    fflush(stdout);
  }
  l = min(M, l);
  if (n == 1) {
    if (run) {
      vector<long long> t;
      for (long long i = 0; i < min(k, l); ++i) {
        if ((t.empty() || t.back() < l + i) && l + i <= M) {
          t.push_back(l + i);
        }
      }
      cout << t.size() << " ";
      for (long long i = 0; i < t.size(); ++i) {
        cout << t[i] << " ";
      }
      cout << '\n';
      fflush(stdout);
      long long ok;
      cin >> ok;
      if (ok < 0) {
        exit(0);
      }
    }
    return min(M, l + min(k, l) - 1);
  }
  if (mp.find(make_pair(n, l)) == mp.end() || run) {
    vector<long long> t(min(k, l));
    t[0] = min(M, dp(n - 1, l, 0) + 1);
    for (long long i = 1; i < min(k, l); ++i) {
      t[i] = min(M, dp(n - 1, t[i - 1] + 1, 0) + 1);
    }
    mp[make_pair(n, l)] = min(M, dp(n - 1, t.back() + 1, 0));
    if (run) {
      vector<long long> tt;
      for (long long i = 0; i < min(k, l); ++i) {
        if ((tt.empty() || tt.back() < t[i]) && t[i] <= M) {
          tt.push_back(t[i]);
        }
      }
      if (tt.empty()) {
        tt.push_back(1);
      }
      cout << tt.size() << " ";
      for (long long i = 0; i < tt.size(); ++i) {
        cout << tt[i] << " ";
      }
      cout << '\n';
      fflush(stdout);
      long long ok;
      cin >> ok;
      if (ok < 0) {
        exit(0);
      }
      if (ok == 0) {
        dp(n - 1, l, 1);
      } else {
        dp(n - 1, tt[ok - 1] + 1, 1);
      }
    }
  }
  return mp[make_pair(n, l)];
}
void solve() {
  long long r = 204761410473;
  cout << 1 << " " << r << '\n';
  fflush(stdout);
  long long ok;
  cin >> ok;
  if (ok < 0) {
    exit(0);
  }
  if (ok == 0) {
    dp(4, 1, 1);
  } else {
    long long n = M - r;
    cout << 10000 << " ";
    for (long long i = 1; i <= 10000; ++i) {
      cout << r + 1 + i * 1000300030001 << " ";
    }
    cout << '\n';
    fflush(stdout);
    cin >> ok;
    if (ok < 0) {
      exit(0);
    }
    long long a = ok * 1000300030001;
    cout << 10000 << " ";
    for (long long i = 1; i <= 10000; ++i) {
      cout << r + 1 + a + i * 100020001 << " ";
    }
    cout << '\n';
    fflush(stdout);
    cin >> ok;
    if (ok < 0) {
      exit(0);
    }
    a += ok * 100020001;
    cout << 10000 << " ";
    for (long long i = 1; i <= 10000; ++i) {
      cout << r + 1 + a + i * 10001 << " ";
    }
    cout << '\n';
    fflush(stdout);
    cin >> ok;
    if (ok < 0) {
      exit(0);
    }
    a += ok * 10001;
    cout << 10000 << " ";
    for (long long i = 1; i <= 10000; ++i) {
      cout << r + 1 + a + i << " ";
    }
    cout << '\n';
    fflush(stdout);
    cin >> ok;
    if (ok < 0) {
      exit(0);
    }
  }
}
int main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
