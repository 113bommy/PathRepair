#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned long long a,b,x;
  cin>>a>>b>>x;
  if(a%x=0){cout<<b/x+1-a/x;}
  else{cout<<b/x-a/x;}
}