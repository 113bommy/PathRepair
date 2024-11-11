#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,ans=0;
  cin>>n;
  for(int i=1; i<=n; i++){
    int m=log10(i)
    if(m%2==1) ans++;
  }
  cout<<ans<<endl;
}