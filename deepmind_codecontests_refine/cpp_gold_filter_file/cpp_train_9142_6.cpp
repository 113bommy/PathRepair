#include<bits/stdc++.h>
using namespace std;
  int main(){
int N;
  cin>>N;
  set<int>S;
  for(int i=0;i<N;i++){
  int x;
    cin>>x;
  S.insert(x);
  }int ans=S.size();
  cout<<ans<<endl;
   return 0;
}