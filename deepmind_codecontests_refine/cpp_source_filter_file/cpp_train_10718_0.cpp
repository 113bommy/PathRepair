#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <fstream>
#include <list>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

typedef int Weight;
struct Edge {
	int s, d;
	Weight w;
	Edge(int s, int d, Weight w) : s(s), d(d), w(w) {};
	bool operator<(const Edge &o)const {
		return w != o.w ? w > o.w : s != o.s ? s < o.s : d < o.d;
	}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
#define EACH(i,t,c) for(t::const_iterator i=(c).begin();i!=(c).end();i++)
Weight augment(const Graph &g, const Matrix &capacity, Matrix &flow, const vi &level, vector<bool> &finished, int u, int t, Weight cur) {
	if(u == t || cur == 0) {
		return cur;
	}
	if(finished[u]) {
		return 0;
	}
	finished[u] = true;
	EACH(e, Edges, g[u]) {
		if(level[e->d] > level[u]) {
			Weight f = augment(g, capacity, flow, level, finished, e->d, t, min(cur, RESIDUE(u, e->d)));
			if(f > 0) {
				flow[u][e->d] += f;
				flow[e->d][u] -= f;
				finished[u];
				return f;
			}
		}
	}
	return 0;
}

Weight maximumFlow(const Graph &g, int s, int t, Matrix &flow) {
	int n = g.size();
	Matrix capacity(n, Array(n));
	REP(u, n) {
		EACH(e, Edges, g[u]) {
			capacity[e->s][e->d] += e->w;
		}
	}
	Weight total = 0;
	bool cont = true;
	while(cont) {
		cont = false;
		vi level(n, -1);
		level[s] = 0;
		queue<int> Q;
		Q.push(s);
		for(int d = n; !Q.empty() && level[Q.front()] < d; ) {
			int u = Q.front();
			Q.pop();
			if(u == t) {
				d = level[u];
			}
			EACH(e, g[u]) {
				if(RESIDUE(u, e->d) > 0 && level[e->d] == -1) {
					Q.push(e->d);
					level[e->d] = level[u] + 1;
				}
			}
		}
		vector<bool> finished(n);
		for(Weight f = 1; f > 0; ) {
			f = augment(g, capacity, flow, level, finished, s, t, INF);
			if(f == 0) {
				break;
			}
			total += f;
			cont = true;
		}
	}
	return total;
}

int main() {
	int N, M;
	cin >> N >> M;
	vi X(M), Y(M);
	Graph o(N, Edges()), c(N, Edges());
	REP(i, M) {
		cin >> X[i] >> Y[i];
		X[i]--;
		Y[i]--;
		o[X[i]].push_back(Edge(X[i], Y[i], 1));
		c[X[i]].push_back(Edge(X[i], Y[i], 1));
		c[Y[i]].push_back(Edge(Y[i], X[i], 1));
	}

	int S, T;
	cin >> S >> T;
	S--;
	T--;
	Matrix flow(N, Array(N, 0));
	Weight maxFlow = maximumFlow(c, S, T, flow);
	cout << maxFlow << endl;
	vi reversedRoads;
	REP(i, M) {
		if(flow[Y[i]][X[i]] > 0) {
			reversedRoads.push_back(i+1);
		}
	}
	int size = reversedRoads.size();
	cout << size << endl;
	REP(i, size) {
		cout << reversedRoads[i] << endl;
	}

	return 0;
}