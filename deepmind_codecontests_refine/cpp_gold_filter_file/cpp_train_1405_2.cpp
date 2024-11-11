#include <bits/stdc++.h>
using namespace std;
int n;
int gears[1001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> gears[i];
  bool done = true;
  for (int i = 0; i < n; i++) {
    done = true;
    for (int j = 0; j < n; j++) {
      if (gears[j] != j) {
        done = false;
        break;
      }
    }
    if (done) {
      cout << "Yes" << endl;
      return 0;
    }
    bool dir = true;
    for (int j = 0; j < n; j++) {
      if (dir)
        gears[j] = (gears[j] + 1) % n;
      else {
        if (gears[j] > 0)
          gears[j]--;
        else
          gears[j] = n - 1;
      }
      dir = !dir;
    }
  }
  cout << "No" << endl;
}
