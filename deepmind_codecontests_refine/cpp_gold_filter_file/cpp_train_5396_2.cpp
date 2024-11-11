#include<bits/stdc++.h>
using namespace std;
#define M 1000000000
int h,w,cnt;
char c[52][52];
vector<vector<int>> a(52,vector<int>(52,M));
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
queue<pair<int,int>> q;
void bfs(int i,int j){
  for(int k=0;k<4;k++){
    if(c[i+dx[k]][j+dy[k]]=='.'){
      if(a[i][j]+1<a[i+dx[k]][j+dy[k]]){
        a[i+dx[k]][j+dy[k]]=a[i][j]+1;
        q.push(make_pair(i+dx[k],j+dy[k]));
      }
    }
  }
}
int main(){
  cin>>h>>w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin>>c[i][j];
      if(c[i][j]=='#'){
        cnt++;
      }
    }
  }
  a[1][1]=1;
  bfs(1,1);
  while(!q.empty()){
    bfs(q.front().first,q.front().second);
    q.pop();
  }
  if(a[h][w]==M)cout<<-1;
  else cout<<h*w-a[h][w]-cnt;
}