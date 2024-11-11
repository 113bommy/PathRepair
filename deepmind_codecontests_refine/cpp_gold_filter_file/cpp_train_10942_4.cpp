#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    long long sum = 0;
    sum += (s / c);
    long long rem = sum / a;
    sum += (rem * b);
    cout << sum << endl;
  }
  return 0;
}
