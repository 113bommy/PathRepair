#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
using namespace std;
main(){
  int m,n;
  while(cin>>m>>n,n){
    int a1[n][n],a2[n][n],q,w,e,r;
    r(i,n)r(j,n){
      if(i==j)a2[i][j]=a1[i][j]=0;
      else a2[i][j]=a1[i][j]=INF;
    }
    while(m--){
      scanf("%d%d%d%d",&q,&w,&e,&r);q--;w--;
      a1[q][w]=a1[w][q]=e;
      a2[q][w]=a2[w][q]=r;
    }
    r(k,n)r(i,n)r(j,n){
      a1[i][j]=min(a1[i][j],a1[i][k]+a1[k][j]);
      a2[i][j]=min(a2[i][j],a2[i][k]+a2[k][j]);
    }
    cin>>e;
    while(e--){
      scanf("%d%d%d",&q,&w,&r)q--;w--;
      if(r)cout<<a2[q][w]<<endl;
      else cout<<a1[q][w]<<endl;
    }
  }
}