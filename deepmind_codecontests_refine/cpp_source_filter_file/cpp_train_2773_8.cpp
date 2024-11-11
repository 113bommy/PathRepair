#include <bits/stdc++.h>
using namespace std;
int h, m, i;
int check() {
  if (h % 10 == 7 || m % 10 == 7) {
    return 0;
  }
  return 1;
}
void dech() {
  if (h - 1 < 0) {
    h = 23;
  } else {
    h--;
  }
}
void dec() {
  if (m - 1 < 0) {
    dech();
    m = 59;
  } else {
    m--;
  }
}
int main() {
  cin >> i >> h >> m;
  if (!check()) {
    cout << 0;
  } else {
    int cnt = 0;
    while (check()) {
      cnt++;
      for (int it = 0; it < 3; it++) {
        dec();
      }
    }
    cout << cnt << endl;
  }
}
