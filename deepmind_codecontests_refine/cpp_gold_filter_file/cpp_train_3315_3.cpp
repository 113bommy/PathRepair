#include <iostream>
using namespace std;
int A,B;
int main(){
  cin >> A >> B;
  cout << ((A%3==0 || B%3==0 || (A+B)%3==0)? "Possible":"Impossible") << endl;
}