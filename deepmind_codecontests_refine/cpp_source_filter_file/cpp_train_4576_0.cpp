#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF 999999999

int main(){
    int n;
    cin>>n;
    rep(loop,n){
        if(loop!=0)cout<<endl;
        string data[30];
        int h,w;
        cin>>h>>w;
        rep(i,h){
            cin>>data[i];
        }
        int x;
        cin>>x;
        string s;
        cin>>s;
        
        pii now;
        char st=' ';
        
        rep(i,h){
            rep(j,w){
                if( data[i][j]=='>' || data[i][j]=='^' || data[i][j]=='<' || data[i][j]=='v' ){
                    now=pii(i,j);
                    st=data[i][j];
                    data[i][j]='.';
                    break;
                }
            }
        }
        rep(i,x){
            if(s[i]=='R'){
                if(now.second+1<w&&data[now.first][now.second+1]=='.'){
                    now.second++;
                }
                st='>';
            }
            if(s[i]=='L'){
                if(now.second-1>=0&&data[now.first][now.second-1]=='.'){
                    now.second--;
                }
                st='<';
            }
            if(s[i]=='D'){
                if(now.first+1<w&&data[now.first+1][now.second]=='.'){
                    now.first++;
                }
                st='v';
            }
            if(s[i]=='U'){
                if(now.first-1<w&&data[now.first-1][now.second]=='.'){
                    now.first--;
                }
                st='^';
            }
            if(s[i]=='S'){
                int y=now.first,x=now.second;
                int dir=0;
                int dx[]={0,1,0,-1};
                int dy[]={1,0,-1,0};
                if(st=='v')dir=0;
                if(st=='>')dir=1;
                if(st=='^')dir=2;
                if(st=='<')dir=3;
                while(1){
                    y+=dy[dir];
                    x+=dx[dir];
                    if(y<0||y>=h||x<0||x>=w)break;
                    if(data[y][x]=='#')break;
                    if(data[y][x]=='*'){
                        data[y][x]='.';
                        break;
                    }
                }
            }
        }
        data[now.first][now.second]=st;
        rep(i,h){
            rep(j,w){
                cout<<data[i][j];
            }
            cout<<endl;
        }
    }
}