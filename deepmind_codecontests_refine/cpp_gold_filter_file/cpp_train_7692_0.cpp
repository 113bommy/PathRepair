#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(){
  int n,m;
  cin>>n>>m;
  char a[50][50];
  int w[50],r[50],b[50];
  lp(i,50){
    w[i]=0;
    r[i]=0;
    b[i]=0;
  }
  lp(i,n){
    lp(j,m){
      cin>>a[i][j];
      if(a[i][j]=='W') w[i]++;
      if(a[i][j]=='R') r[i]++;
      if(a[i][j]=='B') b[i]++;
    }
  }
  int ans=10000;
  lp(i,n-2){
    for(int j=i+1;j<n-1;j++){
      int mem=0;
      for(int k=0;k<=i;k++){
	mem+=r[k]+b[k];
      }
      for(int k=i+1;k<=j;k++){
	mem+=w[k]+r[k];
      }
      for(int k=j+1;k<n;k++){
	mem+=w[k]+b[k];
      }
      if(mem<ans) ans=mem;
    }
  }
  cout<<ans<<endl;
  return 0;
}

