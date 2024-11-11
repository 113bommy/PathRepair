#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  long long n;
  cin >> n;
  fflush(stdout);
  long long bmin = 0;
  long long bmax = 1e9;
  long long bmid;
  long long count = 0;
  while (bmin < bmax) {
    bmid = (bmin + bmax) / 2;
    cout << "> " << bmid << endl;
    fflush(stdout);
    count++;
    long long x;
    cin >> x;
    fflush(stdout);
    if (x == 1) {
      bmin = bmid + 1;
    } else {
      bmax = bmid;
    }
  }
  long long themax = bmax;
  long long ans = 0;
  srand(time(0));
  long long diff = rand();
  for (int i = count; i < 60; i++) {
    if (i - count >= n) break;
    cout << "? " << (diff * i) % n + 1 << endl;
    fflush(stdout);
    long long x;
    cin >> x;
    if (x == themax) continue;
    if (ans == 0) {
      ans = themax - x;
    } else {
      ans = gcd(ans, themax - x);
    }
  }
  cout << "! " << themax - (n - 1) * ans << " " << ans << endl;
  fflush(stdout);
}
