#include<iostream>
using namespace std;
int main(){
  int k,a,b;cin>>k>>a>>b;
  if(k*(int)(b/k)>=a) cout<<"OK"<<endl;
  else cout<<"NG"<<endl;
  return 0;
}
