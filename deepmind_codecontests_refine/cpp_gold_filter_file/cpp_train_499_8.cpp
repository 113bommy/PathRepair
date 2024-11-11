#include<bits/stdc++.h>
using namespace std
;int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  c*=2;
  if(c>a+b)c=a+b;
  if(x>y)cout << y*c+(x-y)*min(c,a);
  else cout << x*c+(y-x)*min(c,b);
}
