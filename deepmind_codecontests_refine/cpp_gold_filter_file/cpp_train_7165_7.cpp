#include <bits/stdc++.h>
using namespace std;
long long n,k[10005],l[10005],mon;
int main(){
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>k[i];
  }
  for(int i=0;i<n;++i){
    cin>>l[i];
    if(k[i]>l[i]){mon-=k[i]-l[i];}
    else if(l[i]>k[i]){mon+=(l[i]-k[i])/2;}
  }
  string ans="Yes";
  if(mon<0){ans="No";}
  cout<<ans<<endl;
}
