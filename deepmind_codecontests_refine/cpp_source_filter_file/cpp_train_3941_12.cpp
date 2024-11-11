#include <iostream>
using namespace std;
int A,B,C;
int main(){
  cin >> A >> B >> C;
  cout << ((A<=C %% C<=B)? "Yes":"No") << endl;
}
