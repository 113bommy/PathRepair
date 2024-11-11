#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int ans=1;
  int a=1;
  for(int i=1;i<N;i++){
   if(A.at(i-1)<A.at(i)){
    if(a==1){
    a=0;
    }else if(a==2){
      ans++; a=1;
    }else
      a=0;
   }
   if(A.at(i)<A.at(i-1)){
    if(a==1){
    a=2;
    }else if(a==0){
      ans++; a=1;
    }else
      a=2;
   }
   }
  }cout<<ans<<endl;
   return 0;
}