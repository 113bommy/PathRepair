#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  int a[100],b[100];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  sort(a,a+n);
  sort(b,b+m);
  int z=min(y,b[0]);
  if(max(x,a[n-1])<z) cout<<"No War";
  else cout<<"War";
}