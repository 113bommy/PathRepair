#include <iostream>
#include <string>
using namespace std;

#define REP(i,N) for(int i=0;i<(N);++i) 
  
int GCD(int a, int b){
  int t;
  while((t = a%b) != 0) {
    a = b;
    b = t;
  }
  return b;
}

int main(){
  int S = 27720, N;
  cin >> N;
  
  if(N==3) {
    cout << "2 3 25" << endl;
    return 0;
  }
  
  for(int i = 2; i < S/2 && N >= 2; ++i){
    if(GCD(i, S) != 1) {
      cout << i << " " << S-i << " ";
      N -=2;
    }
  }
  if(N == 1) 
    cout << S;
  cout << endl;
}