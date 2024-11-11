#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  sort(A.begin(),A.end());
  bool x=true;
  for(int i=0;i<N;i++){
  if(N%2==0){
   if(A.at(i)!=2*(i/2)+1){x=false; break;}
  }else{
  if(A.at(i)!=2*((i+1)/2)){x=false; break;}
  }
  
 }if(!x)
    cout<<0<<endl;
  else{
  int ans=1;
    for(int i=0;i<(N/2);i++){
    ans=(ans*2)%1000000007;
    }cout<<ans<<endl;
  
  
  
  }
   return 0;
}