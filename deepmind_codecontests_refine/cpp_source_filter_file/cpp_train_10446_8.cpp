#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long w, h;
  cin >> w >> h;
  long long count = 0;
  for (long long i = 0; i <= w; i++)
    for (long long j = 0; j <= h; j++) {
      count += min(min(i, w - i), min(j, h - j));
    }
  cout << count << endl;
}
