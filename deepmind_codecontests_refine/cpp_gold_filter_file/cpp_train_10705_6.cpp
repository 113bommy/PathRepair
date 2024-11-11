#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,a=0;cin>>n;
  m=n;
  while(m>0){
    a+=m%10;
    m=m/10;
  }
  if(n%a==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
     
