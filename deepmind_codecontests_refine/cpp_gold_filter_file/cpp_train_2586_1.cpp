#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x=1,b=0;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a.at(i);
  for(int j=0;j<n;j++){
    x=a.at(x-1);
    if(x==2){
      b=j+1;
      break;
    }
  }
  if(b>0)cout<<b<<endl;
  else cout<<-1<<endl;
}
