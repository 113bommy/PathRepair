#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
const long long base = 1e9;
const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long N = 1e5 + 10;
void solve();
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  map<long long, long long> cnt;
  long long k = 0;
  for (long long i = 0; i < n; ++i) {
    if (s[i] != '.') {
      ++cnt[k];
    } else {
      ++k;
    }
  }
  bool f = false;
  for (long long i = 1; i < k; ++i) {
    if (cnt[i] < 2 or cnt[i] > 11) {
      f = true;
      break;
    }
  }
  if (cnt[0] < 1 or cnt[0] > 8 or cnt[k] < 1 or cnt[k] > 3 or f or !k) {
    cout << "NO";
  } else {
    cout << "YES\n";
    f = false;
    if (k == 1) {
      cout << s << "\n";
      return;
    }
    long long j = 1, temp = 0, f1 = 1, f2 = 1;
    for (long long i = 0; i < n; ++i) {
      if (f) {
        if (!temp and f2) {
          if (cnt[j] == 2) {
            temp = 1;
          } else if (cnt[j] == 3) {
            temp = 2;
          } else {
            temp = 3;
          }
          f1 = 1729;
        }
        cout << s[i];
        if (s[i] == '.') {
          f2 = 1729;
          ++j;
          if (j == k) {
            while (i < n - 1) {
              ++i;
              cout << s[i];
            }
          }
        }
        if (temp > 0) {
          --temp;
        }
        if (!temp and f1) {
          cout << "\n";
          f1 = 0;
          f2 = 0;
        }
      } else {
        cout << s[i];
        if (s[i] == '.') {
          f = true;
        }
      }
    }
  }
  cout << "\n";
  return;
}
