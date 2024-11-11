#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long e = 0, o = 0, a, n;
  cin >> n;
  while (n--) {
    cin >> a;
    if ((a & 1) == 1) {
      o += 1;
    } else {
      e += 1;
    }
  }
  if (e > o) {
    cout << o;
  } else {
    cout << o - e + o / 3;
  }
  return 0;
}
