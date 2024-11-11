#include <bits/stdc++.h>
using namespace std;
const unsigned int INF = 2000000001;
const long long INF0 = 2000000001000000001;
const bool DEBUG_OUTPUT = false;
const int modulo = 1000000007;
const int go[8][2] = {{0, 1}, {0, -1},  {1, 0},  {-1, 0},
                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int main() {
  long long n, k;
  int p;
  cin >> n >> k >> p;
  long long a = (n >> 1) + (n & 1);
  long long b = 0;
  if (k >= a) {
    b = k - a;
  } else
    a = k;
  if ((n - 2 * a + 1) >= 0 && ((n - 2 * a + 1) & 1) == 0 && k > 0) {
    b = a - 1;
    a = k - b;
  }
  for (int i = 0; i < p; i++) {
    long long q;
    cin >> q;
    q = n - q;
    if (q & 1) {
      cout << ((q >> 1) < b ? 'X' : '.');
    } else
      cout << ((q >> 1) < a ? 'X' : '.');
  }
}
