#include <iostream>
using namespace std;
int a,b,c;
int main(){
  cin >> a >> b >> c;
  cout << ((a+b==c || b+c==a || c+a==b)? "Yes":"No") << endl;
}
