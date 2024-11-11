#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  if (T == 5) {
    cout << 1 << endl;
    return 0;
  }
  cout << (((T + 1) % 5) ? ((T + 1) % 3) : 3) << endl;
}
