#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ","
       << " ";
  err(++it, args...);
  cout << "\n";
}
bool checkbit(long long mask, long long bit) { return mask & (1ll << bit); }
int setbit(long long mask, long long bit) { return mask | (1ll << bit); }
int clearbit(long long mask, long long bit) { return mask & ~(1ll << bit); }
int togglebit(long long mask, long long bit) { return mask ^ (1ll << bit); }
int bitno(long long mask) { return (long long)__builtin_popcount(mask); }
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
const long long maX = 1e6 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    string str;
    cin >> str;
    bool ok = false;
    for (long long i = 0; i < str.size(); i++) {
      if (str[i] == '0') {
        long long x = n - i;
        if (x >= n / 2 && (x - 1) >= n / 2) {
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
          ok = true;
          break;
        }
      }
    }
    if (ok) continue;
    for (long long i = 0; i < str.size(); i++) {
      if (str[i] == '0') {
        if (i >= n / 2) {
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
          ok = true;
          break;
        }
      }
    }
    if (ok) continue;
    if (n % 2 == 0) {
      cout << 1 << " " << n / 2 << " " << n / 2 + 1 << " " << n << "\n";
    } else {
      cout << 1 << " " << n / 2 << " " << n / 2 + 2 << " " << n << "\n";
    }
  }
  return 0;
}
