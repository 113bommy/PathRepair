#include <bits/stdc++.h>
using namespace std;
long long mgc(long long x, long long y) {
  long long temp;
  while (y) {
    temp = x % y;
    x = y;
    y = temp;
  }
  return x;
}
int main() {
  long long t, w, b, s;
  while (cin >> t >> w >> b) {
    if (w == b) {
      cout << "1/1" << endl;
      continue;
    }
    long long mm = mgc(w, b);
    s = 0;
    if (t / w >= b / mm) {
      mm = b / mm * w;
      s = t / mm * min(w, b) + min(t % mm, min(w, b) - 1);
    } else
      s = min(t, min(w, b) - 1);
    mm = mgc(s, t);
    cout << s / mm << "/" << t / mm << endl;
  }
  return 0;
}
