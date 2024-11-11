#include <iostream>
using namespace std; 
int main(){
  int A, B, C;
  cin >> A >> B >> C >> endl;
  if( ( (A-C) * (B-C) ) < 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
