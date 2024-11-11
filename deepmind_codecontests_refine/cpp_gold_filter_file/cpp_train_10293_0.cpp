#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  int sum=0;
  
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    sum+=a.at(i);
  }
  
  int x=sum/N;
  int y=sum%N;
  if(2*y>N){
    x++;
  }
  
  int cost=0;
  for(int i=0;i<N;i++){
    cost+=(a.at(i)-x)*(a.at(i)-x);
  }
  
  cout<<cost<<endl;
}