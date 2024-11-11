#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
int main(){
  int n,k,a=0;string s;cin>>n>>k>>s;
  REP(i,n-2)
    if(s[i]==s[i+1])a++;
  cout<<min(n-1,k*2+a)<<endl;
}
