#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  cout << min(A, B) << " " << (A + B - 2 * min(A, B)) / 2;
  return 0;
}
