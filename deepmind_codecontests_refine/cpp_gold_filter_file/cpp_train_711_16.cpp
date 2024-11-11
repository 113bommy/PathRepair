#include <iostream>
using namespace std;
int main(){
  int a,b,ans=1;
  cin>>a>>b;
  for(int i=1;i<a;i++)
    ans*=(b-1);
  cout<<b*ans<<endl;
}