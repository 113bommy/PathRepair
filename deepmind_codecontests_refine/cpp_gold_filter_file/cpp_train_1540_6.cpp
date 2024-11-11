#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  int D;
  for(int i=0;i<M;i++){
    cin>>D;
    N-=D;
  }

  if(N<0)cout<<-1<<endl;
  else cout<<N<<endl;
}