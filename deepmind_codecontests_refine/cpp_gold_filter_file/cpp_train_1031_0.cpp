#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

int n;
int t[100],c[100];
int maxt[2];

struct state{
  int t,pc,r,idx;
};

bool operator<(const state& a,const state& b){
  if(a.t==b.t)return a.pc > b.pc;
  else return a.t > b.t;
}

int main(){
  while(1){
    cin>>n;
    if(n==0)break;
    rep(i,n)cin>>t[i]>>c[i];
    priority_queue<state> que;
    memset(maxt,0,sizeof(maxt));
    rep(i,n){
      que.push((state){0,t[i],0,(int)i});
      c[i]*=2;
    }
    while(que.size()){
      state s=que.top(); que.pop();
      int nxt=max(maxt[s.r],s.t+s.pc);
      maxt[s.r]=nxt;
      c[s.idx]--;
      if(c[s.idx]>0){
        que.push((state){nxt,s.pc,1-s.r,s.idx});
      }
    }
    cout<<max(maxt[0],maxt[1])<<endl;
  }
  return 0;
}

