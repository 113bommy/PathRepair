#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  string a,b; int ans=0;
  cin>>a; b="CODEFESTIVAL2016";
    rep(i,16) if(a[i]!=b[i]) ans++;
  cout<<ans<<endl;
}
