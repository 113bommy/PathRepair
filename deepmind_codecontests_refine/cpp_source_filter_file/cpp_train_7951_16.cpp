#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  cin >> n;
  long long ans = 0, half = 0;
  int a = 1, b = 1;
  for (int c = 1; c <= n; ++c) {
    for (int a = 1; a <= 100; ++a) {
      int b2 = c * c - a * a;
      int sqr = sqrt((double)b2);
      if (b2 > 0 && sqr * sqr == b2) {
        ++ans;
        if (sqr != a) ++half;
      } else if (b2 < 0)
        break;
    }
  }
  cout << (ans - half / 2) << endl;
  return 0;
}
