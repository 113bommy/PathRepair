#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  cin >> n >> r;
  cout << r + 100 * min(10 - n, 0) << endl;
}
