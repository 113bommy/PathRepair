#include <bits/stdc++.h>
using namespace std;
int hsh[5000];
int main() {
  int h, m, n;
  cin >> h >> m >> n;
  for (int i = 0; i < 5000; i++) {
    hsh[i] = -1;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      int id, hh;
      cin >> id >> hh;
      while (hsh[hh] != -1) {
        hh = (hh + m) % n;
        cnt++;
      }
      hsh[hh] = id;
    } else {
      int id;
      cin >> id;
      for (int j = 0; j < n; j++) {
        if (hsh[j] == id) {
          hsh[j] = -1;
          break;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
