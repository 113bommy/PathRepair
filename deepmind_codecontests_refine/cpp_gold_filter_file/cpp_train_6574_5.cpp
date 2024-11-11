#include <bits/stdc++.h>
using namespace std;
int n;
int bs(int c) {
  int second = 1, e = n;
  int r;
  while (second <= e) {
    int mid = (second + e) / 2;
    cout << "? " << 1 << " " << c << " " << mid << " " << c << endl;
    int x;
    cin >> x;
    if (x % 2) {
      r = mid;
      e = mid - 1;
    } else
      second = mid + 1;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    cin >> n;
    int c1 = -1, c2 = -1, r1 = -1, r2 = -1;
    for (int i = 1; i < n; i++) {
      cout << "? " << 1 << " " << i << " " << n << " " << i << endl;
      int x;
      cin >> x;
      if (x % 2) {
        if (c1 == -1)
          c1 = i;
        else
          c2 = i;
      }
    }
    if (c1 != -1) {
      if (c2 == -1) c2 = n;
      r1 = bs(c1);
      r2 = bs(c2);
    } else {
      for (int i = 1; i < n + 1; i++) {
        cout << "? " << i << " " << 1 << " " << i << " " << n << endl;
        int x;
        cin >> x;
        if (x % 2) {
          if (r1 == -1) {
            int second = 1, e = n;
            r1 = i;
            while (second <= e) {
              int mid = (second + e) / 2;
              cout << "? " << i << " " << 1 << " " << i << " " << mid << endl;
              int y;
              cin >> y;
              if (y % 2) {
                c1 = mid;
                e = mid - 1;
              } else
                second = mid + 1;
            }
          } else {
            r2 = i;
            c2 = c1;
            break;
          }
        }
      }
    }
    cout << "! " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  }
  return 0;
}
