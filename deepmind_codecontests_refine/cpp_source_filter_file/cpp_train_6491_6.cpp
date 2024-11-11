#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  long long p, d;
  cin >> p >> d;
  long long result = p;
  long long c = 10;
  while (c <= p) {
    long long r;
    if (p % c == c - 1) {
      r = p;
    } else {
      long long a = result / c;
      r = (a - 1) * c + c - 1;
    }
    if (p - r <= d) {
      result = r;
    }
    c *= 10;
  }
  cout << result << endl;
  return 0;
}
