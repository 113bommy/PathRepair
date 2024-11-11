#include <bits/stdc++.h>
using namespace std;
int ask(int i) {
  cout << "? " << i << endl;
  int x;
  cin >> x;
  return x;
}
int signum(int i) { return i < 0 ? -1 : i > 0 ? 1 : 0; }
int main(int argc, char** argv) {
  int n;
  cin >> n;
  if (n % 4) {
    cout << "! -1" << endl;
    return 0;
  } else {
    int m = n / 2;
    vector<int> as(n + 1, 0);
    as[n] = as[0] = ask(0);
    as[m] = ask(m);
    int l1, r1, l2, r2;
    l1 = 0;
    r1 = m;
    l2 = m;
    r2 = n;
    while (as[l1] != as[l2]) {
      int m1 = (l1 + r1) / 2;
      int m2 = (l2 + r2) / 2;
      as[m1] = ask(m1);
      as[m2] = ask(m2);
      if (signum(as[l1] - as[l2]) * signum(as[m1] - as[m2]) < 0) {
        r1 = m1;
        r2 = m2;
      } else {
        l1 = m1;
        l2 = m2;
      }
    };
    cout << "! " << l1;
  }
  return 0;
}
