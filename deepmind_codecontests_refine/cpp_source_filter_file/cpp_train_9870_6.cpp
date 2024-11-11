#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  cout << (A < 6 ? 0 : (B < 13 ? B / 2 : B)) << endl;
  return 0;
}
