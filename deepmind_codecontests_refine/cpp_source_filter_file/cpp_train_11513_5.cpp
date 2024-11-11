#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string out = "";
  cin >> n >> k;
  int h = 0;
  while (n--) {
    out = out + (char)(97 + h);
    h = (h + 1) % 27;
  }
  cout << out << endl;
  return 0;
}
