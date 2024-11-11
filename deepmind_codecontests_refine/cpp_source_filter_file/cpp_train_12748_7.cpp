#include <bits/stdc++.h>
using namespace std;
int x, y, n;
int main() {
  cin >> n;
  int p = 1;
  for (int i = 1; i < n; i++) {
    p = (p + i) % n;
    if (p == 0) p++;
    cout << p << " ";
  }
  cout << endl;
}
