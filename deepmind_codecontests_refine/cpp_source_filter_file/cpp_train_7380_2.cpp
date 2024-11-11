#include<bits/stdc++.h>
#define int long long
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
static const int INF = 1ll<<60;
typedef pair<int,int> pii;

struct P{
    int x;
    int y;
    p(){}
    P(int p1,int p2){
        x=p1;
        y=p2;
    }
};


int W,H;
int N;
int dis[100010];
vector<int> posx;
vector<int> posy;
vector<P> pos;

int dist(int x,int y){
    int res=0;
    for(int i=0;i<N;++i){
        int disx=abs(x-pos[i].x);
        int disy=abs(y-pos[i].y);
        dis[i]=disx+disy;
    }
    sort(dis,dis+N);
    for(int i=0;i<N-1;++i)res+=dis[i]*2;
    res+=dis[N-1];
    return res;
}

signed main(){
    cin>>W>>H;
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x>>y;
        posx.PB(x);
        posy.PB(y);
        pos.PB(P(x,y));
    }
    if(N%2!=0){
        sort(posx.begin(),posx.end());
        sort(posy.begin(),posy.end());
        int x=posx[N/2];
        int y=posy[N/2];
        int ans=dist(x,y);
        cout<<ans<<endl;
        cout<<x<<" "<<y<<endl;
    }
    else{
        sort(posx.begin(),posx.end());
        sort(posy.begin(),posy.end());
        int ans=INF;
        int x,y;
        int d1=dist(posx[N/2-1],posy[N/2-1]);
        int d2=dist(posx[N/2-1],posy[N/2]);
        int d3=dist(posx[N/2],posy[N/2-1]);
        int d4=dist(posx[N/2],posy[N/2]);
        if(ans>d1){
            ans=d1;
            x=posx[N/2-1];
            y=posy[N/2-1];
        }
        if(ans>d2){
            ans=d2;
            x=posx[N/2-1];
            y=posy[N/2];
        }
        if(ans>d3){
            ans=d3;
            x=posx[N/2];
            y=posy[N/2-1];
        }
        if(ans>d4){
            ans=d4;
            x=posx[N/2];
            y=posy[N/2];
        }
        cout<<ans<<endl;
        cout<<x<<" "<<y<<endl;
    }
}