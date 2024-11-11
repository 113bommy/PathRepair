#include <iostream>
using namespace std;

int N,a,b,c;

int main(){
  for(;;){
    cin >> N;
    if(N!=0){
      a = 1;
      b = 0;
      for(int i = 0; i < N; i++){
        cin >> c;
        if(c != 0){
          a++;
        }
        if(c > 1){
          b++;
        }
      }
      if(b == 0){
        cout << "NA" << endl;
      }else{
        cout << a << endl;
      }
    }else{
      break;
    }
  }
}