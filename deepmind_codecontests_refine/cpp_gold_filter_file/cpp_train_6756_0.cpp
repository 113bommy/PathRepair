#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int n,m,a[101][101];
  while(cin>>n>>m,n){
    r(i,n)r(j,n)a[i][j]=(i==j)?0:1e9;
    while(m--){
      int t,q,w,e;
      cin>>t;
      if(t){
        cin>>q>>w>>e;
        if(a[--q][--w]>e){
          a[q][w]=a[w][q]=e;
          r(i,n)r(j,n)
            a[i][j]=min(a[i][j],min(a[i][q]+a[q][w]+a[w][j],a[j][q]+a[q][w]+a[w][i]));
        }
      }
      else{
        cin>>q>>w;
        if(a[--q][--w]!=1e9)cout<<a[q][w]<<endl;
        else cout<<(-1)<<endl;
      }
    }
  }
}