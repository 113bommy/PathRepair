#include <bits/stdc++.h>
using namespace std;

int main(){
int A,B;
  cin>>A>>B;
  string ans;
  if(A+B==15) ans='+';
  else if(A*B==15) ans='*';
  else ans='x';
  cout<<ans<<endl;
}