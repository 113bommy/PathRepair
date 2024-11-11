#include <iostream>
using namespace std;
int f,s,x;
int main(){
  for(int i=0;i<3;i++){
  	cin>>x;
    f+=(x==5);
    s+=(x==7);
  }
  if(f==2&&s==1) cout<<"YES";
  else cout<<"NO";
}
