#include <iostream>
using namespace std;

int main(){
  int a,b;
  double x,y,k;

  cin >> a >> b;
  x = a * 2.0;
  y = b;
  k = a+1 + b+ 1 -2;
  for(int i=1;i<a;i++){
    for(double j=1.0;j<y;j++){
      //cout << i+2.0*(y/x) << endl;
      if(i*2.0*(y/x) == j){
        k--;
        break;
      }
    }
  }
  cout << k << endl;
}


