#include <bits/stdc++.h>
#define N 1401
using namespace std;
int mp[N][N];
int h,w;

struct dat{int h,i;};

int calc(int A[]){
  stack <dat> S;
  int res = 0;
  for(int i=0;i<=w;i++){
    int h = A[i];
    if(S.empty() || S.top().h < h) S.push((dat){h,i});
    else if(S.top().h > h){
      int ni = i;
      while(!S.empty() && S.top().h > h){
        dat t = S.top(); S.pop();
        ni = t.i;
        int area = (i - t.i) * t.h;
        res = max(res,area);
      }
      res = max(res,(i-ni)*h);
      S.push((dat){h,ni});
    }
  }
  return res;
}

int main(){

  cin>>h>>w;
  
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)cin>>mp[i][j],mp[i][j]=!mp[i][j];
  
  for(int j=0;j<w;j++)
    for(int i=1;i<h;i++)if(mp[i][j]) mp[i][j] = mp[i-1][j]+1;


  //cout<<endl;for(int i=0;i<h;i++){for(int j=0;j<w;j++)cout<<mp[i][j]<<" ";cout<<endl;}
  int ans = 0;
  for(int i=0;i<h;i++)ans = max(ans,calc(mp[i]));
  cout<<ans<<endl;
  return 0;
}