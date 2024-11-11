#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ini = 0, out = 0, hit = 0, cnt = 0  ;
  while (ini < n) {
    string s;
    cin >> s;
    if (s == "OUT") {
      out++;
      if (out == 3) {
        cout << cnt << endl;
        cnt = 0;
        hit = 0;
        out = 0;
        ini++;
      }
    }
    if (s == "HIT") {
      if (hit == 3) {
        cnt++;
      } else {
        hit++;
      }
    }

    if (s == "HOMERUN") {
      cnt += hit + 1;
      hit = 0;
    }
  }
}
