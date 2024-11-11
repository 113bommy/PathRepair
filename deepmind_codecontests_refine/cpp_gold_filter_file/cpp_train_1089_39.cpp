#include <bits/stdc++.h>
using namespace std;
long long h, n, d;
long long go(long long ch, long long a, long long b, int com) {
  long long ans = 0;
  long long mid = (a + b - 1) / 2;
  ;
  ;
  ;
  if (ch == 1) {
    return 0;
  }
  if (com) {
    if (d <= mid) {
      return go(ch - 1, a, mid, !com) + 1;
    } else {
      return go(ch - 1, mid + 1, b, com) + (1ll << (ch - 1));
    }
  } else {
    if (d > mid) {
      return go(ch - 1, mid + 1, b, !com) + 1;
    } else {
      return go(ch - 1, a, mid, com) + (1ll << (ch - 1));
    }
  }
}
int main() {
  cin >> h >> d;
  cout << go(h + 1, 1, 1ll << (h), 1) << endl;
}
