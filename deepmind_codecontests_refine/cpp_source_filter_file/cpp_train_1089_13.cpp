#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, n;
  cin >> h >> n;
  long long low = 1, high = (1LL << h), mid, res = 0, step = 0;
  while (low < high) {
    mid = (low + high) / 2;
    if (n > mid) {
      low = mid + 1;
      if (step == 1)
        res++, step = 0;
      else
        res += (1LL << h);
    } else {
      high = mid;
      if (step == 0)
        res++, step = 1;
      else
        res += (1LL << h);
    }
    h--;
  }
  cout << res << endl;
  return 0;
}
