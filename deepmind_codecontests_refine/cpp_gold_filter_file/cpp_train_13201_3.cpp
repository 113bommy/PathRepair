#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B,p=0,q=0;cin>>N>>A>>B;
  vector<int> a(N);
  for(int i=0;i<N;i++)cin>>a.at(i);
  sort(a.begin(),a.end());
  
  for(int i=0;i<N;i++){
    if(a.at(i)<=A)p++;
    else if(a.at(i)>B)q++;
  }
  
  int ans=min(p,q);
  ans=min(ans,N-p-q);
  cout<<ans<<endl;
}