#include <iostream>
using namespace std;

int main() {
  int d;
  cin >> d;
  cout << "Christmas";
  for (int eveI = 0; eveI <= 25 - d; ++eveI;) cout << " Eve";
  cout << endl;
}