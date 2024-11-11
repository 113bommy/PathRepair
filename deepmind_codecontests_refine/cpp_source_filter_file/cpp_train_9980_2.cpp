#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define ll long long

using namespace std;

const ll INF = LLONG_MAX / 2 - 1;


struct Edge {
	ll t;
	ll c;
	Edge(ll to, ll cost):t(to),c(cost){}
	Edge(){}
};

vector<ll> weigh;
ll R, C;

bool DFS(ll node, vector<vector<Edge> >& edge, ll& xmin, ll& ymin) {
	if (node < R) xmin = min(xmin, weigh[node]);
	else ymin = min(ymin, weigh[node]);
	for (auto &to : edge[node]) {
		if (weigh[to.t] == INF) {
			weigh[to.t] = to.c - weigh[node];
			if (not DFS(to.t, edge, xmin, ymin)) return false;
		}
		else {
			if (weigh[to.t] + weigh[node] != to.c) return false;
		}
	}
	return true;
}
int main() {
	cin >> R >> C;
	ll N;
	cin >> N;
	weigh.resize(R + C, INF);
	vector<vector<Edge> > edge(R+C);
	for(int i = 0; i < N; i++){
		ll r, c, a; cin >> r >> c >> a;
		--r; --c;
		edge[r].push_back(Edge(R+c,a));
		edge[R+c].push_back(Edge(r, a));
	}

	bool res = true;
	ll xmin, ymin;
	for(int i = 0; i < R + C; i++){
		if(weigh[i] == INF and edge[i].size() > 0) {
			xmin = ymin = numeric_limits<int>::max();
			weigh[i] = 0;
			if (not DFS(i,edge,xmin,ymin) or xmin+ymin < 0) {
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
}
