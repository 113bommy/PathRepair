#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin>>N;
  int a=1;
  for(int64_t i=1;i*i<=N;i++){
  if(N%i==0)
    a=i;
 }
  int64_t ans=a+(N/a)-2;
  
  cout<<ans<<endl;
return 0;
}