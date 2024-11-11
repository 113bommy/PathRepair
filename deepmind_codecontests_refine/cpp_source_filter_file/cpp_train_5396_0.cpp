#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main(){
    ll h,w;
    cin>>h>>w;
    vector<string> board(h);
    rep(i,h) cin>>board[i];
    ll cnt=0;
    rep(i,h)rep(j,w) if(board[i][j]=='#') cnt++;
    queue<pair<ll,ll>> q;
    vector<vector<ll>> dist(h,vector<ll>(w,-1)); 
    q.push(make_pair(0,0));
    dist[0][0]=0;
    while(!q.empty()){
        ll f=q.front().first;
        ll s=q.front().second;
        q.pop();
        rep(i,4){
            ll y=f+dy[i],x=s+dx[i];
            if(y>=0&&y<h&&x>=0&&x<w&&board[y][x]=='.'&&dist[y][x]==-1){
                q.push(make_pair(y,x));
                dist[y][x]=dist[f][s]+1;
            }
        }
    }
    if(dist[h-1][w-1]==-1) cout<,-1<<endl;
    else cout<<h*w-cnt-dist[h-1][w-1]-1<<endl;
    return 0;
}