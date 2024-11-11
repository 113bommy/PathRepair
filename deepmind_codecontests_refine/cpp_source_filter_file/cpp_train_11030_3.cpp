#include<bits/stdc++.h>
#define r(i,a,n) for(int i=a;i<n;i++)
double a[21][3],ans=0,p;int n,m,c[21];
using namespace std;
double cal(){p=0;
  r(i,0,m)r(j,i+1,m)
  p+=pow(a[c[i]][0]-a[c[j]][0],2)+pow(a[c[i]][1]-a[c[j]][1],2)+pow(a[c[i]][2]-a[c[j]][2],2);
  ans=max(ans,p);
}
void dfs(int x,int d){
  if(d==m){cal();return;}
  else if(x==n)return;
  c[d]=x;dfs(x+1,d+1);dfs(x+1,d);
}
int main(){
  cin>>n>>m
    r(i,0,n)cin>>a[i][0]>>a[i][1]>>a[i][2];
    dfs(0,0);
    printf("%.12d\n",ans);
  
}