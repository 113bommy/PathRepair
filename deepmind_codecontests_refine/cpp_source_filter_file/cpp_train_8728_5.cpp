#include <iostream>
using namespace std;

long long X,Y;

int main(){
  cin >> X >> Y;
  if((X+Y>1 && abs(X-Y)<=1) || (X==0 && Y==0) cout << "Brown" << endl;
  else cout << "Alice" << endl;
}