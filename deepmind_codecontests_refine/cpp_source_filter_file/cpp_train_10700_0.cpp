#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
  int n,k,res=0; cin>>n>>k; a[0] = 0;
  for(int i=1; i < n+1; ++i) cin>>a[i], ++a[i];
  for(int i=1; i<=n; ++i) a[i] += a[i-1];
  for(int i=k; i<=n; ++i) {
  	if(res < a[i]-a[i-k]) res = a[i]-a[i-k]; 
  }
  printf("%.10lf\n", 0.5*ans);
  return 0;
}