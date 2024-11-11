#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef long long W;

const W INF = 1LL << 50;

struct edge {
	int to;
	W cost;
};
typedef pair<W, int> P;
typedef vector<vector <edge > > Graph;

vector<W> dijkstra(int s, const Graph& G) {
	vector<W> d(G.size());
	priority_queue< P, vector<P>, greater<P> > que;
	fill(d.begin(), d.end(), INF);
	d[s] = 0;
	que.push(P(0, s));
	while(!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	return d;
}

template <class T>
struct BIT {
	int n;
	vector<T> x;
	BIT(int n_ = 0) : n(n_), x(n + 1, 0) {}
	int size() const { return n; }
	T sum(int r) const {
		T S = 0;
		for(r = r - 1; r >= 0; r = (r & (r + 1)) - 1) S += x[r];
		return S;
	}
	T sum(int l, int r) const { return sum(r) - sum(l); }
	void add(int k, const T &a) {
		for(; k < n; k |= k + 1) x[k] += a;
	}
	void set(int k, const T &a) { add(k, a - sum(k, k + 1)); }
	int lower_bound(T x) {
		int ng = -1, ok = n_ - 1;
		while(abs(ng - ok) > 1) {
			int mid = (ng + ok) / 2;
			if(b.sum(0, mid + 1) >= x) ok = mid;
			else ng = mid;
		}
		return ok;
	}
};

struct Q {
	ll fs, fg;
	int id;
	bool operator <(const Q& x) const {
		return fs < x.fs;
	}
};

typedef pair<ll, ll> Pll;

int ans[100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	Graph G(n);
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({ b, c });
		G[b].push_back({ a, c });
	}

	vector<W> ds = dijkstra(0, G);
	vector<W> dg = dijkstra(n - 1, G);
	vector<Pll> dd(n);
	map<W, int> dg_map;
	for(int i = 0; i < dg.size(); i++) {
		dg_map[dg[i]] = -1;
		dd[i] = { ds[i], dg[i] };
	}
	sort(dd.begin(), dd.end());
	int cnt = 0;
	for(auto v : dg_map) {
		dg_map[v.first] = cnt++;
	}

	int qn;
	cin >> qn;
	vector<Q> qs(qn);
	for(int i = 0; i < qn; i++) {
		cin >> qs[i].fs >> qs[i].fg;
		qs[i].id = i;
	}
	sort(qs.begin(), qs.end());

	BIT<ll> b(cnt);
	int di = 0;
	for(auto q : qs) {
		while(di < n && dd[di].first <= q.fs) {
			int idx = dg_map[dd[di].second];
			b.add(idx, 1);
			di++;
		}
		auto it = dg_map.lower_bound(q.fg);
		if(it == dg_map.end()) continue;
		ans[q.id] = b.sum(it->second, cnt);
	}

	for(int i = 0; i < qn; i++) {
		cout << ans[i] << endl;
	}
}