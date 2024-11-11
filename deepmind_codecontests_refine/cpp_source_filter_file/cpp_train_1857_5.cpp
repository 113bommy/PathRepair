#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,S,x=1;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++)cin>>a.at(i);
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  S=0
  for(int i=0;i<N;i++){
    S+=x*a.at(i),x=-x;
  }
  cout<<S<<endl;
}