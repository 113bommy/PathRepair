#include <iostream>
using namespace std;
int A[13] = {0,1,3,1,2,1,2,1,1,2,1,2,1},a,b;

int main(){
  cin >> a >> b;
  cout << (A[a]==A[b]? "Yes":"No") << endl;
}