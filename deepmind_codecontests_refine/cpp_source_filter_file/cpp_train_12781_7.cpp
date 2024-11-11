#include <iostream>
 
using namespace std;
 
int main(){
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int O = 0;
  while (A >= B){
    B *= 2;
    O += 1;
  }
  while (B >= C){
    C *= 2;
    O += 1;
  }
  if (O > K){ cout << "No"};
  else{ cout << "Yes"};
}