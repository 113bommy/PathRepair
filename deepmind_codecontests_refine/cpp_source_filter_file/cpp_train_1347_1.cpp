#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;
#define INF (1 << 30)
typedef pair<int, int> P;
typedef pair<int, P> T;

vector<P> edge[105];
int n, m, l, k, a, h;
bool recover[105];
int dist[105][105];

void dijkstra(int s){
	for(int i = 0;i < 105;i++)
		for(int j = 0;j < 105;j++)
			dist[i][j] = INF;
	dist[s][m] = 0;
	priority_queue<T, vector<T>, greater<T> > pq;
	pq.push(T(0, P(s, m)));
	while(!pq.empty()){
		T tmp = pq.top();pq.pop();
		int d = tmp.first, from = tmp.second.first, blood = tmp.second.second;
		if(dist[from][blood] < d)continue;
		for(int i = 0;i < edge[from].size();i++){
			int to = edge[from][i].first, r = edge[from][i].second;
			if(r > blood)continue;
			if(dist[to][blood - r] <= d + r)conitnue;
			dist[to][blood - r] = d + r;
			pq.push(T(dist[to][blood - r], P(to, blood - r)));
		}
		if(blood < m && recover[from]){
			if(dist[from][blood + 1] <= d + 1)continue;
			dist[from][blood + 1] = d + 1;
			pq.push(T(dist[from][blood + 1], P(from, blood + 1)));
		}
	}
}

int main(){
	int t, x, y;
	while(cin >> n >> m >> l >> k >> a >> h, n){
		fill(recover, recover + 105, false);
		for(int i = 0;i < 105;i++)edge[i].clear();
		for(int i = 0;i < l;i++){
			cin >>t;
			recover[t] = true;
		}
		for(int i = 0;i < k;i++){
			cin >> x >> y >> t;
			edge[x].push_back(P(y, t));
			edge[y].push_back(P(x, t));
		}
		dijkstra(a);
		int res = INF;
		for(int i = 0;i < 105;i++){
			res = min(res, dist[h][i]);
		}
		if(res == INF)cout <<"help!" << endl;
		cout << res << endl;	
	}
	return 0;
}