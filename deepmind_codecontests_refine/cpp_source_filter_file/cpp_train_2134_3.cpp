#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, w1, h1, w2, h2;
  int p1, p2, dx, dy;
  cin >> h >> w >> h1 >> w1 >> h2 >> w2;
  p1 = p2 = 0;
  if ((h1 + h2) <= h && max(w1, w2) <= w) {
    cout << "YES" << endl;
  } else {
    if ((w1 + h2) <= h && max(h1, w2) <= w) {
      cout << "YES" << endl;
    } else {
      if ((w1 + w2) <= h && max(h1, h2) <= w) {
        cout << "YES" << endl;
      } else {
        if ((h1 + w2) <= h && max(w1, h2) <= w) {
          cout << "YES" << endl;
        } else {
          if ((w1 + w2) <= w && max(h1, h2) <= h) {
            cout << "YES" << endl;
          } else {
            if ((h1 + w2) <= w && max(w1, h2) <= h) {
              cout << "YES" << endl;
            } else {
              if ((w1 + h2) <= w && max(h1, w2) <= h) {
                cout << "YES" << endl;
              } else {
                if ((w1 + w2) <= w && max(h1, h2) <= h) {
                  cout << "YES" << endl;
                } else
                  cout << "NO" << endl;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
