#include <iostream>
using namespace std;
int main(){
  int k,r,n=0;
  cin >> k >> r;
  while(k){
    k=k/r;
    n++
  }
  cout << n;
  return 0;
}
