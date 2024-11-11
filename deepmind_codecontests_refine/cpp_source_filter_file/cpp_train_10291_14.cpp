#include<iostream>

using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int s={0,1,3,1,2,1,2,1,1,2,1,2,1};
  if(s[a]==s[b])cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}