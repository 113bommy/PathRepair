#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0)
    cout << 0 << endl;
  else {
    int cur = 1;
    for (int i = 1; i < n; ++i) cur = (cur * 3) % (1000003);
    cout << cur << endl;
  }
}
