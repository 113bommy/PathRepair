#include<iostream>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  if(13<=a) cout<<b;
  else if(6<=a && a<=12) cout<<b/2;
  else cout<<"0";

}
