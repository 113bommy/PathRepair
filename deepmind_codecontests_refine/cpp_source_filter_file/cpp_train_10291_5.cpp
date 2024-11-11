#include<iostream>
using namespace std;
int main(){
  int c[12]={0,1,3,1,2,1,2,1,1,2,1,2,1};
  int a,b;
  cin>>a>>b;
  if(c[a]==c[b])
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}