#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  int v[10] = {2, 6, 2, 3, 3, 3, 2, 5, 1, 2};
  while (cin >> n) {
    int x = n[0] - '0', y = n[1] - '0';
    cout << v[x] * v[y] << endl;
  }
  return 0;
}
