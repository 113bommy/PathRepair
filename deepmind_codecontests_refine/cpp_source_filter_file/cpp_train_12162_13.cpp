#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,ans;
  cin>>a>>b>>c;
  ans=max(10*a+b+c,a+10*b+c,a+b+10*c);
  cout<<ans;
  return 0;
}
