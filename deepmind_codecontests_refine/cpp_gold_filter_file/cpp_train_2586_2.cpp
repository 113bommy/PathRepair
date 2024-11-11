#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a[110000];
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  int t=a[1],cnt=1;
  for(int i=0;i<n;i++){
    if(t==2){ cout<<cnt; return 0; }
    t=a[t];
    cnt++;
  }
  cout<<"-1";
}
