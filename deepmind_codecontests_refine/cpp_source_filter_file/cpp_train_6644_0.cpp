#include <Bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
 int res=0;
  while(n>0){
  res+=(n%10);
    n/=10;
  }
  if(res==1) cout << "10" << endl;
  else cout << res << endl;
}