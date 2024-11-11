#include <bits/stdc++.h>
using namespace std;
int main() {
  bool ans[16] = {1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0};
  int a;
  cin >> a;
  cout << (ans[a - 1] == 1) ? 1 : 0;
  cout << endl;
  return 0;
}
