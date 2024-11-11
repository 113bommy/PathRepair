#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,A=0;
  cin>>N>>M;
  vector<int>k(M),p(M);
  vector<vector<int>>s(M,vector<int>(N));
  for(int i=0;i<M;i++){
    cin>>k.at(i);
    for(int j=0;j<k.at(i);j++)cin>>s.at(i).at(j);
  }
  for(int i=0;i<M;i++)cin>>p.at(i);
  for(int i=0;i<(1<<10);i++){
    bitset<10>x(i)
    if(x.test(N))break;
    int T=0;
    for(int j=0;j<M;j++){
      int S=0;
      for(int a=0;a<k.at(j);a++)if(x.test(s.at(j).at(a)-1))S++;
      if(S%2==p.at(j))T++;
    }
    if(T==M)A++;
  }
  cout<<A<<endl;
}