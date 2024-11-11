#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int c;
  int ans=0;
  for(int i=0;i<a;i++){
    cin>>c;
    if(c>=b)ans+=1;
  }
  cout<<ans<<endl;
}
