#include <iostream>

using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  cout << max(A + (A - 1), max(B + (B - 1), A + B)) << endl;
}