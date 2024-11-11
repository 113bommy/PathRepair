#include <iostream>
using namespace std;
int main(){
  int ans=700;
string h;
  cin>>h;
  
  for(int i=0;i<3;i++){
  if(h[i]=='o') ans+=100;
  }
  cout<<ans<<endl;
}
