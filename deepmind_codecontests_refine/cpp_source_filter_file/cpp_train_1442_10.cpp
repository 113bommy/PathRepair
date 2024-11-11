#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((b * 10 + c) % 4 == 0 ? "Yes" : "No") << endl;
}
