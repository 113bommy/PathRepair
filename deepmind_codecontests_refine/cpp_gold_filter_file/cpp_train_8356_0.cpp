#include <bits/stdc++.h>
using namespace std;
void init() {}
class Timer {
 private:
  chrono::time_point<chrono::steady_clock> Begin, End;

 public:
  Timer() : Begin(), End() { Begin = chrono::steady_clock::now(); }
  ~Timer() {
    End = chrono::steady_clock::now();
    cerr << "\nDuration: " << ((chrono::duration<double>)(End - Begin)).count()
         << "s\n";
  }
} T;
int32_t main() {
  init();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long l = 1; l <= t; l++) {
    long long n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " 0 0\n";
      continue;
    }
    if (n % 5 == 0) {
      cout << "0 " << n / 5 << " 0\n";
      continue;
    }
    if (n % 7 == 0) {
      cout << "0 0 " << n / 7 << "\n";
      continue;
    }
    long long max3 = n / 3, max5 = n / 5, max7 = n / 7;
    bool done = false;
    for (long long i = 0; i <= max3; i++) {
      for (long long j = 0; j <= max5; j++) {
        for (long long k = 0; k <= max7; k++) {
          if (3 * i + 5 * j + 7 * k == n) {
            cout << i << " " << j << " " << k << "\n";
            done = true;
            break;
          }
        }
        if (done) break;
      }
      if (done) break;
    }
    if (!done) cout << "-1\n";
  }
}
