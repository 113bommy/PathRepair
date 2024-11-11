#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0;
  string st = "";
  for (i = 1; i < 300; i++) {
    std::ostringstream oss;
    oss << i;
    st = st + oss.str();
  }
  int q;
  cin >> q;
  cout << st[q - 1] << endl;
  return 0;
}
