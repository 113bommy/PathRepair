#include <iostream>
using namespace std;

int main(){

  int a[10001] ;
  a[1] = 2;
  for(int i=2;i<=10000;i++) a[i] = a[i-1] + i;

  int n;
  while(cin >> n){
  cout << a[n] << endl;
  }
  
  return 0;
}


  