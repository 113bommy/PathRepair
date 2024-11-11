#include<iostream>
using namespace std;

int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if (b>x+a)cout<< "dangerous"<<endl;
  else if (b>a) cout<<"safe"<<endl;
  else cout<<"delicious"<<endl;
  
  
}