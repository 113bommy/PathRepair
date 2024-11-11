#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int T;
  cin >> T;
  int n;
  for (int c1 = 0; c1 < T; c1++) {
    cin >> n;
    for (int c2 = 0; c2 < n; c2++) {
      cout << c2 + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
