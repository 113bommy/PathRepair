#include <iostream>
using namespace	std;

int main() {
  int A, B, C, D, L;
  int X, Y;

  cin >> L >> A >> B >> C >> D;

  X = A/C;
  if(A%C != 0)
    X++;
  Y = B/D;
  if(B%D != 0)
    Y++;

  cout << (X>Y) ? L-X :	L-Y << endl;
}
