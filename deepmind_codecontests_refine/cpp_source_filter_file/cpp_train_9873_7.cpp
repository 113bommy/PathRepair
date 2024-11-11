#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B;cin>>N>>A>>B;
  int ans=0;
  int P;
  int x;
  for(int i=1;i<N+1;i++){
    P=0;
    x=i
    while(x){
      P+=x%10;
      x=(x-x%10)/10;
    }
    if(A<=P && P<=B)ans+=i;
  }
  cout<<ans<<endl;
}