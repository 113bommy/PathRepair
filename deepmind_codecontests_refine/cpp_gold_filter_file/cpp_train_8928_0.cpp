#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Z{
  ll y;
  ll x;
  ll depth;
};

ll H,W,K,y,x,depth,oo=1e12,xs,ys,xg,yg;
vector<ll> y_vec={1,0,-1,0};
vector<ll> x_vec={0,1,0,-1};
vector<vector<ll>> A;
queue<Z> q;

ll bfs(){
  while(!q.empty()){
    Z now=q.front(); q.pop();
    y=now.y, x=now.x, depth=now.depth;
    if(y==yg && x==xg) return depth;
    for(ll i=0; i<4; i++){
      for(ll k=1; k<=K; k++){
        Z next={y+y_vec[i]*k, x+x_vec[i]*k, depth+1};
//cout<<"ny:"<<next.y<<" nx:"<<next.x<<endl;        
        if(A[next.y][next.x]==-1) break;
        if(A[next.y][next.x]<next.depth) break;
        if(A[next.y][next.x]==next.depth) continue;
        A[next.y][next.x]=next.depth;
        q.push(next);
//cout<<" d:"<<next.depth<<endl;          
      }
    }
  }
  return oo;
}

//A[y][x], A(x,y)として管理
int main(){
  cin>>H>>W>>K;
  cin>>ys>>xs>>yg>>xg;
  A.assign(H+2, vector<ll>(W+2,-1));
  for(int i=1; i<=H; i++){
    for(int j=1; j<=W; j++){
      char a; cin>>a;
      if(a=='@') continue;
      A[i][j]=oo;
    }
  }
  A[ys][xs]=0;
  Z start={ys,xs,0};
  q.emplace(start);
  ll ans=bfs();
  if(ans==oo) ans=-1;
  cout<<ans<<endl;
}
