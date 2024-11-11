#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  long long f=min({a,b,c,d,e});
  if(f==1) cout<<n/f+4<<endl;
  else cout<<n/f+5<<endl;
}