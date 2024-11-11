#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int i;
  string c;
  for(i=0;i<=1+b;i++){
    cout<<"#";
  }
  cout<<endl;
  for(i=0;i<a;i++){
    cin>>c;
    cout<<"#"<<c<<"#"<<endl;
  }
  for(i=0;i<=1+b;i++){
    cout<<"#";
  }
  cout<<endl;
}