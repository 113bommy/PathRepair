#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char x,y,ans='=';cin>>x>>y;
  if(x<y)ans='<';
  else if(x>y)ans='>';
  cout << ans << endl;
}