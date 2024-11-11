#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,c,d,a,b,e,k;
map<int,int> ans;
int main(){
  for(cin>>n>>m;i<m;i++){
    cin>>b>>c;
    if(b>n)return cout<<-1,0;
    if((n!=1&&b==1&&c==0)return cout<<-1,0;
    if(ans[b]==0||ans[b]==c)ans[b]=c;
    else return cout<<-1, 0;
  }
  if(n==3){
    if(ans[1]==0)ans[1]=1;
    cout<<ans[1]*100+ans[2]*10+ans[3];
  }else if(n==2){
    if(ans[1]==0)ans[1]=1;
    cout<<ans[1]*10+ans[2];
  }else{
    cout<<ans[1];
  }
}