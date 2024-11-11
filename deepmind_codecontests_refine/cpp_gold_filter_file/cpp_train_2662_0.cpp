#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string x;
  cin >> x;
  if (x[a - 1] == x[b - 1])
    cout << "0" << endl;
  else
    cout << "1" << endl;
  return 0;
}
