#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int a[12] = {0, 1, 2, 1, 3, 1, 3, 1, 1, 3, 1, 3, 1};
  cout << (a[x]==a[y]?"Yes":"No") << endl;
}
