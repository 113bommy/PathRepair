#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  map<int,int>M;
  for(int i=0;i<N;i++){
  int a;
    cin>>a;
      if(M.count(a))
        M.erase(a);
    else
      M[a]=1;
 }int ans=M.size();
  cout<<ans<<endl;
    return 0;
}