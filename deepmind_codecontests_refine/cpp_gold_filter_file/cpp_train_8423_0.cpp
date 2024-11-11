#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

map<string, int> id;
vector<pi> e[6000];
int n, m, cap, sz;
bool f[6000];
int get(const string &s){
	if(id.count(s)) return id[s];
	return id[s] = sz++;
}

int main(){
	while(cin >> n >> m >> cap, n){
		id.clear(); sz = 0;
		
		string s, t;
		cin >> s >> t;
		int si = get(s), ti = get(t);
		
		rep(i, n){
			int d, a, b;
			cin >> s >> t >> d;
			a = get(s); b = get(t);
			e[a].pb(mp(b, d));
			e[b].pb(mp(a, d));
		}
		f[si] = f[ti] = 1;
		rep(i, m){
			cin >> s;
			f[get(s)] = 1;
		}
		vector<vi> ds;
		vi ss;
		rep(i, sz) if(f[i]) ss.pb(i);
		
		rep(ii, ss.size()){
			int s = ss[ii];
			priority_queue<pi> q;
			q.push(mp(0, s));
			vi dist(sz, inf), d2;
			
			while(!q.empty()){
				int c = q.top().second, co = q.top().first;
				q.pop();
				
				if(dist[c] <= -co) continue;
				dist[c] = -co;
				rep(i, e[c].size()){
					if(dist[e[c][i].first] > -co + e[c][i].second)
					q.push(mp(co - e[c][i].second, e[c][i].first));
				}
			}
			rep(i, ss.size()) d2.pb(dist[ss[i]] <= cap * 10 ? dist[ss[i]] : inf);
			ds.pb(d2);
		}
		
		int l = ds.size();
		rep(k, l) rep(i, l) rep(j, l) ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
		
		cout << (ds[0][1] >= inf ? -1 : ds[0][1]) << endl;
		
		rep(i, sz) e[i].clear(), f[i] = 0;
	}
	return 0;
}