#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,C,K,S=0;cin>>N>>C>>K;
  vector<int>T(N);
  for(int i=0;i<N;i++)cin>>T.at(i);
  sort(T.begin(),T.end());
  for(int i=0;i<N;i++){
    S++;int j=1;
    while(i+j<N&&j<C&&T.at(i)+K>=T.at(i+j))j++;
    i+=j-1;
  }
  cout<<S<<endl;
}