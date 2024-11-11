#include <bits/stdc++.h>
using namespace std;
int n;
int ask(int x) {
  cout << "? " << x + 1 << endl;
  fflush(stdout);
  int ret;
  cin >> ret;
  return ret;
}
int ask2(int x) {
  int x1 = ask(x), x2 = ask((x + n / 2) % n);
  return x2 - x1;
}
void ans(int x) {
  cout << "! " << x + 1 << endl;
  fflush(stdout);
}
int main() {
  cin >> n;
  if (n % 4) {
    ans(-2);
    return 0;
  }
  int lo = 0, hi = n / 2;
  int meglo = ask2(0), meghi = -meglo;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    int meg = ask2(mid);
    if (meg * meglo < 0) {
      meghi = meg;
      hi = mid;
    } else {
      meglo = meg;
      lo = mid;
    }
  }
  ans(lo);
}
