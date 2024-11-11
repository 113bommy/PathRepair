#include<bits/stdc++.h>
using namespace std;

bool judge(long long int x,int n){
  if((n-x)%(2*x+1)==0){return true;}
  return false;
}



int main(){
  int count=0;
  int m;
  cin>>m;
  for(int t=0;t<m;t++){


    
  int n;
  cin>>n;
  if(n==0){break;}
  bool j=true;
  for(int x=1;x*x<=n;x++){
    if(judge(x,n)){j=false; break;}
  }
  if(j){count++;}



  }


  cout<<count<<endl;
  
    
  return 0;
