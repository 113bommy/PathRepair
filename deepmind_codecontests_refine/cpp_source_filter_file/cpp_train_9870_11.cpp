#include <bits/stdc++.h>
using namesapce std;
main(){
  int a,b;
  cin>>a>>b;
  int ans=0;
  if (a>=6 && a<=12) ans+=b/2;
  else if (a>=13) ans+=b;
  cout<<ans;
}