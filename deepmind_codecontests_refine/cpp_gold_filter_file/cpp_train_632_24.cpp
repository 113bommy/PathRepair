#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, K;
  cin >> n >> K;
  int q;
  cin >> q;
  while (q--) {
    long long x;
    cin >> x;
    --x;
    long long k = K;
    long long N = n;
    if (n % 2) {
      if (x == n - 1) {
        cout << (k ? "X" : ".");
        continue;
      } else {
        if (k) {
          --k;
          --N;
        } else {
          cout << ".";
          continue;
        }
      }
    }
    long long t1 = k, t2 = 0;
    if (t1 > N / 2) t1 = N / 2, t2 = k - N / 2;
    long long upper_odd = N + 1 - 2 * t1;
    long long upper_even = N - 2 * t2;
    bool res = ((x % 2 == 1) && (upper_odd <= x)) ||
               ((x % 2 == 0) && (upper_even <= x));
    cout << (res ? "X" : ".");
  }
  cout << endl;
}
