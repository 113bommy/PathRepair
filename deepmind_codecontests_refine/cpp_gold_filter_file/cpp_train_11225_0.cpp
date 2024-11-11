#include <bits/stdc++.h>
using namespace std;
long long f[333][333][333];

long long solution(int n,int x,int y){
  f[0][1][0]=1;
  for(int i=0;i<=n;i++)
    for(int j=1;j<=x;j++)
      for(int p=i;p>=0;p--){
          if(p) (f[i][j][p-1]+=f[i][j][p]) %= y;
          else (f[i][j+1][i]+=f[i][j][p]) %= y;
          (f[i+1][j][p]+=f[i][j][p]*(p+1)) %= y;
      }
  return f[n][x + 1][n];
}

int main()
{
  int n, x ,y;
  n = 2;
  x = 3;
  y = 100;
  cin>>n>>x>>y;
  long long res = solution(n, x, y);
  cout<<res<<endl;
  return 0;
}
