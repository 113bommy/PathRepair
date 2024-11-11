#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<int> W(N); 
  int S=0;
  for(int i=0; i<N; i++){
    cin>>W[i];
    S+=W[i];
  }
  int L=0; int Ans=10001
  for(int i=0; i<N; i++){
    L+=W[i]; S-=W[i];
    if(abs(L-S)<Ans)
      Ans=abs(L-S);
  }
  cout<<Ans<<endl;
}
