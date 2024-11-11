#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    string b;
    cin >> a;
    cin >> b;
    int cnta = 0;
    int cntb = 0;
    for (int i = 0; i < a; i++) {
      if (b[i] == 'a') {
        cnta++;
      } else
        cntb++;
    }
    if (cnta == 0 || cntb == 0) {
      cout << -1 << " " << -1 << endl;
    } else {
      cnta = 0;
      cntb = 0;
      for (int i = 0; i < a; i++) {
        if ((b[i] == 'a' && b[i + 1] == 'b') ||
            (b[i] == 'b' && b[i + 1] == 'a')) {
          cout << i << " " << i + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
