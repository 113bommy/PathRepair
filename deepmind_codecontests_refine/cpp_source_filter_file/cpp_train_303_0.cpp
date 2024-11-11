#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
struct edge { int to, cap, rev; };//ikisaki youryou gyakuhen
#define MAX 200
vector<vector<edge> >G(MAX);//[MAX];
vector<bool>used(MAX);//[MAX];
void add_edge(ll from, ll to, ll cap){
	edge q={to,cap,ll(G[to].size())};
    G[from].push_back(q);
	q={from,0,ll(G[from].size()-1)};
    G[to].push_back(q);
}

ll dfs(ll v, ll t, ll f) {
    if(v == t) return f;
    used[v] = 1;
    for(int i = 0 ; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(used[e.to] || e.cap <= 0) continue;
        ll d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
        }
    }
    return 0;
}
ll ford_fulkerson(ll s, ll t) {//from s to t
    ll flow = 0, f;
    while(1){
		used=vector<bool>(MAX,false);
        f = dfs(s, t, inf);
        if(f == 0) return flow;
        flow += f;
    }
}
int gcd(int a,int b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	ll n,m;
	map<string,int>ma;
	ma["Sunday"]=0;
	ma["Monday"]=1;
	ma["Tuesday"]=2;
	ma["Wednesday"]=3;
	ma["Thursday"]=4;
	ma["Friday"]=5;
	ma["Saturday"]=6;
	while(cin>>n>>m,n+m){
		rep(i,MAX)G[i].clear();
		ll s=n+7,t=s+1;
		ll out=0;
		rep(i,n){
			ll c,d;
			cin>>c>>d;
			out+=c;
			add_edge(s,i,c);
			rep(j,d){
				string ss;
				cin>>ss;
				add_edge(i,n+ma[ss],m);
			}
		}
		rep(i,7)add_edge(n+i,t,m);
		if(ford_fulkerson(s,t)==out)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}