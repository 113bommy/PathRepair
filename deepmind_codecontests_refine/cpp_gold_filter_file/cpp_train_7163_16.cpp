#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;cin>>n>>a>>b;
  int c; c= a+b-n;
  if(c<0)c=0;
  cout<<min(a,b)<<" "<<c<< endl;
}
