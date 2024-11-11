#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, k;
  while (cin >> l >> r >> k) {
    if (l == r) {
      cout << l << endl;
      cout << 1 << endl;
      cout << l << endl;
    } else {
      if (k == 1) {
        cout << l << endl;
        cout << 1 << endl;
        cout << l << endl;
        continue;
      } else if (l + 1 == r) {
        if ((l ^ r) < l) {
          cout << (l ^ r) << endl;
          cout << 2 << endl;
          cout << l << " " << r << endl;
        } else {
          cout << l << endl;
          cout << 1 << endl;
          cout << l << endl;
        }
      } else if (l + 2 == r) {
        if (l == 1 && k > 2) {
          cout << 0 << endl;
          cout << 3 << endl;
          cout << "1 2 3" << endl;
        } else {
          if (l & 1) l++;
          cout << 1 << endl;
          cout << 2 << endl;
          cout << l << " " << l + 1 << endl;
        }
      } else {
        if (k == 3 || (l + 3 == r)) {
          bool find = false;
          long long t = 1;
          while (t <= l) t <<= 1;
          t += t / 2;
          if (t <= r) {
            cout << 0 << endl;
            cout << 3 << endl;
            cout << (t ^ (t - 1)) << " " << t << " " << t - 1 << endl;
            find = true;
          }
          if (find) continue;
        }
        if (k < 4 || (l + 3 == r && (l & 1))) {
          if (l & 1) l++;
          cout << 1 << endl;
          cout << 2 << endl;
          cout << l << " " << l + 1 << endl;
        } else {
          if (l & 1) l++;
          cout << 0 << endl;
          cout << 4 << endl;
          cout << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
        }
      }
    }
  }
  return 0;
}
