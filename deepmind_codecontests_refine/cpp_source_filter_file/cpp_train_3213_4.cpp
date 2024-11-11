#include <iostream>
using namespace std;

int main() {
  long long int A, B, X; cin >> A >> B >> X;
  cout << B/X - A/X + (A%X == 0) << endl;
  reutrn 0;
}