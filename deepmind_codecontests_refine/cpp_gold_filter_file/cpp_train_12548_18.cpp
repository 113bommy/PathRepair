#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1 << endl;
    return 0;
  }
  cout << 6 << endl;
  cout << 10 << endl;
  cout << 15 << endl;
  for (int i = 3; i < n; i++) {
    cout << 6 * i << endl;
  }
  return 0;
}
