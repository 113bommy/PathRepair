#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 4; n > 0; n--) {
      cout << i << " ";
      i += 2;
    }
    cout << endl;
  }
  return 0;
}
