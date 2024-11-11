//AOJ0278

#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  for(int i=0; i<N; i++){
    int x, y, b, p;
    cin >> x >> y >> b >> p;

    int f1 = x*b + y*p;

    if(b<5){
      b = 5;
    }
    if(p<2){
      p = 2;
    }
    int f2 = (x*b + y*p)*4/5;

    if(f1<f2){
      cout << f1 << endl;
    }
    else{
      cout << f2 << endl;
    }
  }

  return 0;
}