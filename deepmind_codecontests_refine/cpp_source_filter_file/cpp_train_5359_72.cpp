#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x, y, k;
  cin >> n >> m;
  cin >> x;
  map<int, string> boy;
  while (x--) {
    cin >> k;
    boy[k] = "happy";
  }
  cin >> y;
  map<int, string> girl;
  while (y--) {
    cin >> k;
    girl[k] = "happy";
  }
  int mx = n + m;
  for (int i = 0; i <= mx; i++) {
    int bb, gg;
    bb = i % n;
    gg = i % m;
    if (boy[bb] == "happy")
      girl[gg] = "happy";
    else if (girl[gg] == "happy")
      boy[bb] = "happy";
  }
  map<int, string>::iterator itb;
  map<int, string>::iterator itg;
  itb = boy.begin();
  itg = girl.begin();
  while (itb != boy.end()) {
    if (itb->second != "happy") {
      cout << "No";
      return 0;
    }
    itb++;
  }
  while (itg != girl.end()) {
    if (itg->second != "happy") {
      cout << "No";
      return 0;
    }
    itg++;
  }
  cout << "Yes";
  return 0;
}
