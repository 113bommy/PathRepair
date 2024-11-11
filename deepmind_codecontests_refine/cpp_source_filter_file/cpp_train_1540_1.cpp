#include <iostream>
using namespace std;

int main(){
  int a,b,c,d;
  cin>>a>>b;
  c=0
  for(int i=0;i<b;i++){
    cin>>d;
    c+=d;
  }
  if(a-c<0)cout<<-1;
  else cout<<a-c;
}