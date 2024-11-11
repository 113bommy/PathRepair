#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long t, a, b;
    cin >> t >> a >> b;
    if (a < b) {
      cout << t * a << endl;
    } else {
      cout << (t / 2) * b + (t % 2) * a << endl;
    }
  }
}
