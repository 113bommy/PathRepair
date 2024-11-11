#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  for (int i = 1; i <= a; i++) {
    string p;
    int ans1 = 0, ans2 = 0;
    cin >> p;
    if (p.size() == 1) {
      cout << p << endl;
    } else {
      for (int l = 0; l <= p.size() - 2; l++) {
        if (p[l] == 'a' && p[l + 1] == 'b') {
          ans1++;
        } else if (p[l] == 'b' && p[l + 1] == 'a') {
          ans2++;
        } else {
        }
      }
      int ans = abs(ans1 - ans2);
      if (ans1 > ans2) {
        for (int l = 0; l <= p.size() - 2; l++) {
          if (ans == 0) {
            break;
          }
          if (p[l] == 'a' && p[l + 1] == 'b' || p[l - 1] != 'b') {
            p[l] = 'b';
            ans--;
          } else if (p[l] == 'b' && p[l - 1] == 'a' || p[l + 1] != 'a') {
            p[l] = 'a';
            ans--;
          } else {
          }
        }
      } else if (ans1 < ans2) {
        for (int l = 0; l <= p.size() - 2; l++) {
          if (ans == 0) {
            break;
          }
          if (p[l] == 'b' && p[l + 1] == 'a' || p[l - 1] != 'a') {
            p[l] = 'a';
            ans--;
          } else if (p[l] == 'a' && p[l - 1] == 'b' || p[l + 1] != 'b') {
            p[l] = 'b';
            ans--;
          } else {
          }
        }
      } else {
      }
      cout << p << endl;
    }
  }
  return 0;
}
