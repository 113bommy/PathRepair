#include<bits/stdc++>h>
using namespace std;
int main(){
  string O,E;cin>>O>>E;
  int M=O.size(),N=E.size();
  for(int i=0;i<N;i++)cout<<O.at(i)<<E.at(i);
  if(M>N)cout<<O.at(M);
  cout<<endl;
}