#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int N,x,s=0;cin>>N>>x;
  vector<int>a(N);
  for(int i=0;i<N;i++)cin>>a.at(i);
  sort(a.begin(),a.end());
  int i;
  for(i=0;i<N;i++){
    s+=a.at(i);
    if(s>x)break;
  }
  if(s==x)cout<<N<<endl;
  else if(s>x)cout<<i<<endl;
  else cout<<N-1<<endl;
}