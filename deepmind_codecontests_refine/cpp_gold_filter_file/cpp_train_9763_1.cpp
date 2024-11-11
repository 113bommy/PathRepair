#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  cout<<min(a,k)-max(0,k-a-b)<<"\n";
}