#include <iostream>

using namespace std;

int main(){
  int a,b,k;
  cin>>a>>b>>k;
  for(int i=0;i<k;i++){
    if(i&1){
      b/=2;
      a+=b;
    }
    else{
      a/=2;
      b+=a;
    }
  }
  cout<<a<<" "<<b;
}
    
