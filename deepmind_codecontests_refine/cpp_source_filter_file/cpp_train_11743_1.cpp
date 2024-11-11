#include<bits/stdc++.h>
using namespace std;

int a[510][510];
int n;

void f(){int l,int r,int k){
  if(r-l==1)return;
  
  int m=(r+l)/2;
  
  for(int i=l;i<m;i++){
    for(int j=m;j<r;j++){
      a[i][j]=k;
    }
  }
  
  f(l,m,k+1);
  f(m,r,k+1);
}

signed main(){
  cin>>n;
  f(0,n,1);
  
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}