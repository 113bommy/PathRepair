#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k;
  int s = 0;
  cin >> t >> k;
  string h;
  string u = "YCM";
  for (int i = 0; i < t; i++) {
    for (int o = 0; o < k; o++) {
      cin >> h;
      if (h[0] == u[0] || h[0] == u[1] || h[0] == u[2]) {
        s++;
      }
    }
  }
  if (s > 0) {
    cout << "#Color" << endl;
  } else {
    cout << "Black&White" << endl;
  }
}
