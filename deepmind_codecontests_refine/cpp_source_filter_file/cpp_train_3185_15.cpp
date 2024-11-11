#include <bits/stdc++.h>
using namespace std;
int main() {
  int limak, bob, i, count;
  cin >> limak >> bob;
  for (i = 1;; i++) {
    limak = limak * 3;
    bob = bob * 2;
    if (limak >= bob) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
