#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,ans;
  cin>>a>>b>>c;
  ans=max(0,c-a+b);
  cout<<ans<<endl;
}