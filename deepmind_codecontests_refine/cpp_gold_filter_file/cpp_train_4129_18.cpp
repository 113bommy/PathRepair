#include <bits/stdc++.h>
using namespace std;
template <class T>
string toString(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
int main(int argc, char *argv[]) {
  int n, w, a, b;
  cin >> n >> w >> a >> b;
  int res = 0;
  if (a == 1 && b == n) {
    cout << "1" << endl;
    return 0;
  }
  if (b == n) {
    int d = n / w + (n % w != 0);
    b = d * w;
  }
  if (b - a + 1 <= w) {
    int d = a / w;
    if (a % w != 0) d++;
    if (d * w < b)
      cout << "2" << endl;
    else
      cout << "1" << endl;
    return 0;
  }
  if ((a - 1) % w == 0 && b % w == 0) {
    cout << "1" << endl;
    return 0;
  }
  if ((a - 1) % w == 0 || b % w == 0) {
    cout << "2" << endl;
    return 0;
  }
  int dd = w - (a - 1) % w, ddd = b % w;
  dd += ddd;
  res = 2;
  if (b - a + 1 - dd >= w) res++;
  if ((a - 1) % w == b % w) res--;
  cout << res << endl;
  return 0;
}
