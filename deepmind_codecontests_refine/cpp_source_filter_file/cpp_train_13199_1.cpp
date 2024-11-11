#include <iostream>
#include <cmath>
using namespace std;
int main(){
  long long N;
  cin>>N;
  long long x=sqrt(N)+1;
  while(n%x!=0){
    x--;
  }
  cout<<x+n/x-2;
}
