#include <bits/stdc++.h>
using namespace std;
using graph = vector<vector<int>>;

struct RMS {
	using ll = long long;
	static const ll INF = 1e17;
	struct type {
		ll left, right, all, sum;
		type() : left(-INF), right(-INF), all(-INF), sum(0) {}
		type(ll val) : left(val), right(val), all(val), sum(val) {}
		type(ll l, ll r, ll a, ll s) : left(l), right(r), all(a), sum(s) {}
	};
	static type id() { return type(); }
	static type op(const type& l, const type & r) {
		return type(max(l.left, l.sum + r.left), max(r.right, r.sum + l.right), max({ l.all, r.all, l.right + r.left }), l.sum + r.sum);
	}
};

class lct_node {
	using M = RMS;
	using T = typename M::type;
	using U = int;

	lct_node *l, *r, *p;
	bool rev;
	T val, all;
	int size;
	bool flag;
	U lazy;

	int pos() {
		if (p && p->l == this) return -1;
		if (p && p->r == this) return 1;
		return 0;
	}
	void update() {	// * fix
		size = (l ? l->size : 0) + (r ? r->size : 0) + 1;
		all = M::op(l ? l->all : M::id(), M::op(val, r ? r->all : M::id()));
	}
	void update_lazy(U v) {	// * fix
		val = T(v);
		all = v > 0 ? T(v * size) : T(v, v, v, v * size);
		lazy = v;
		flag = true;
	}
	void rev_data() {	// * fix
		swap(val.left, val.right);
		swap(all.left, all.right);
	}
	void push() {
		if (pos()) p->push();
		if (rev) {
			swap(l, r);
			if (l) l->rev ^= true, l->rev_data();
			if (r) r->rev ^= true, r->rev_data();
			rev = false;
		}
		if (flag) {
			if (l) l->update_lazy(lazy);
			if (r) r->update_lazy(lazy);
			flag = false;
		}
	}
	void rot() {
		lct_node *par = p;
		lct_node *mid;
		if (p->l == this) {
			mid = r;
			r = par;
			par->l = mid;
		}
		else {
			mid = l;
			l = par;
			par->r = mid;
		}
		if (mid) mid->p = par;
		p = par->p;
		par->p = this;
		if (p && p->l == par) p->l = this;
		if (p && p->r == par) p->r = this;
		par->update();
		update();
	}
	void splay() {
		push();
		while (pos()) {
			int st = pos() * p->pos();
			if (!st) rot();
			else if (st == 1) p->rot(), rot();
			else rot(), rot();
		}
	}

public:
	lct_node() : l(nullptr), r(nullptr), p(nullptr), rev(false), val(M::id()), all(M::id()), size(1), flag(false) {}
	lct_node(const T& v) : l(nullptr), r(nullptr), p(nullptr), rev(false), val(v), all(v), size(1), flag(false) {}
	void init(U v) {
		val = all = T(v);
	}
	void expose() {
		for (lct_node *x = this, *y = nullptr; x; y = x, x = x->p) x->splay(), x->r = y, x->update();
		splay();
	}
	void link(lct_node *x) {
		x->expose();
		expose();
		p = x;
	}
	void cut() {
		expose();
		l->p = nullptr;
		l = nullptr;
		update();
	}
	void evert() {
		expose();
		rev = true;
		rev_data();
	}
	T find() {
		expose();
		return all;
	}
	void update(U v) {
		expose();
		update_lazy(v);
	}
};

const int MAX = 2e5;

lct_node lct[MAX];
int w[MAX];

void build(int v, int prev, const graph& G) {
	lct[v].init(w[v]);
	for (auto to : G[v]) if (to != prev) {
		build(to, v, G);
		lct[to].link(&lct[v]);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	graph G(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	build(0, -1, G);
	while (Q--) {
		int t, a, b, c;
		cin >> t >> a >> b >> c; a--, b--;
		if (t == 1) {
			lct[a].evert();
			lct[b].update(c);
		}
		else {
			lct[a].evert();
			printf("%d\n", (int)lct[b].find().all);
		}
	}
	return 0;
}

