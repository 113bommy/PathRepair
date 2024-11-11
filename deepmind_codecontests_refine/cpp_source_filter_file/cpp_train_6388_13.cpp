#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
void run() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n < 3)
      cout << 0 << endl;
    else
      cout << n / 2 << endl;
  }
}
int main() { run(); }
