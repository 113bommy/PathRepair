#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M; 
  cin>>N>>M;
  vector<int> cnt(M,0);
  for(int i=0;i<N;++i){
     int K; cin>>K;
     for(int j=0;j<K;++j){
      int S; cin>>S;
      ++cnt[S-1];
       }
 }
  int T=0;
  for(int f=0;f<M;++f){
     if(cnt[f]==N){
         ++T;
     }
   }
  cout<<T;
}