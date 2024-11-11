#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,S=0,X=0;cin>>N;vector<int>d(N);
  for(int i=0;i<N;i++){
    cin>>d.at(i);S+=d.at(i);
  }
  for(int i=0;i<N;i++)X+=(S-d.at(i))*d.at(i);
  cout<<X/2<<endl;
}