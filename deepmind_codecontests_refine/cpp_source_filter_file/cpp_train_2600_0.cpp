#include <bits/stdc++.h>
using namespace std;

#define rep(i,b) for(int i=0;i<(b);++i)
typedef pair<int,int> pii;
int h,w;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int dp[55][55][4];
vector<string> v;
bool check(int a,int b){
    if(0<=a&&a<h&&0<=b&&b<w) return true;
    return false;
}
int foo(int a,int b,int c){
    if(!check(a,b)) return 0;
    if(dp[a][b][c]>=0) return dp[a][b][c];
    dp[a][b][c]=0;
    int ret=0;
    if(v[a][b]=='G'){
        return dp[a][b][c]=1;
    }
    rep(k,4){
        int cc=(c-1+k+4)%4;
        if(v[a+dy[cc]][b+dx[cc]]!='#'){
            ret=foo(a+dy[cc],b+dx[cc],cc);
            break;
        }    
    }
    return dp[a][b][c]=ret;
}   

int main(){
    cin>>h>>w;
    v=vector<string>(h+2);
    rep(i,h) cin>>v[i+1];
    v[0]=v[h+1]=string(w+2,'#');
    reep(i,1,h+1){
        v[i]="#"+v[i]+"#";
    }
    h+=2;
    w+=2;
    char y[]="<^>v";
    pii pos;
    int vec;
    rep(i,h){
        rep(j,w){
            rep(k,4) if(v[i][j]==y[k]) pos=pii(i,j),vec=3-k,v[i][j]='.';
        }
    }
    rep(i,55) rep(j,55) rep(k,4) dp[i][j][k]=-1;
    foo(pos.first,pos.second,vec);
    set<pii> se;
    pii gg;
    rep(i,55){
        rep(j,55){
            if(check(i,j)&&v[i][j]=='G') gg=pii(i,j);
            rep(k,4){
                if(dp[i][j][k]==1) se.insert(pii(i,j));
            }
        }
    }
    if(se.find(gg)==se.end()) cout<<-1<<endl;
    else cout<<se.size()<<endl;
}