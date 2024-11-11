#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
//const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

typedef vi Poly;

const Poly ZERO(51, 0);
const Poly INF(51, 1e8);

Poly operator-(const Poly& a, const Poly b)
{
	Poly res(51);
	REP(i, 51) res[i] = a[i] - b[i];
	return res;
}

Poly operator+(const Poly& a, const Poly b)
{
	Poly res(51);
	REP(i, 51) res[i] = a[i] + b[i];
	return res;
}

bool operator<(const Poly& a, const Poly& b)
{
	for (int i = 50; i >= 0; i--)
	{
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return false;
}

bool operator<=(const Poly& a, const Poly& b)
{
	for (int i = 50; i >= 0; i--)
	{
		if (a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return true;
}

bool operator>(const Poly& a, const Poly& b)
{
	for (int i = 50; i >= 0; i--)
	{
		if (a[i] == b[i]) continue;
		return a[i] > b[i];
	}
	return false;
}

Poly min(const Poly& a, const Poly& b)
{
	for (int i = 50; i >= 0; i--)
	{
		if (a[i] == b[i]) continue;
		if (a[i] < b[i]) return a;
		else return b;
	}
	return b;
}

bool resid(const Poly& a)
{
	for (int i = 50; i >= 0; i--)
	{
		if (a[i] == 0) continue;
		return a[i] > 0;
	}
	return false;
}

template <typename Flow>
struct FEdge {
	int from, to;
	Flow cap; int rev;
	FEdge(int s, int t, Flow f, int r) : from(s), to(t), cap(f), rev(r) {}
};

template<typename Flow> using FGraph = vector<vector<FEdge<Flow>>>;

template <typename Flow>
void add_edge(FGraph<Flow> &g, int from, int to, Flow cap) {
	g[from].emplace_back(from, to, cap, (int)g[to].size());
	g[to].emplace_back(to, from, 0, (int)g[from].size() - 1);
}

template <typename Flow>
Flow augment(FGraph<Flow> &g, vi &d, vector<int> &iter, int v, int t, const Flow &f) 
{
	if (v == t || !resid(f)) return f;
	for (int &i = iter[v]; i < (int)g[v].size(); i++) {
		auto &e = g[v][i];
		if (e.cap > ZERO && d[v] < d[e.to]) {
			Flow ff = augment(g, d, iter, e.to, t, min(f, e.cap));
			if (resid(f)) {
				e.cap = e.cap - ff;
				g[e.to][e.rev].cap = g[e.to][e.rev].cap + ff;
				return ff;
			}
		}
	}
	return ZERO;
}

template <typename Flow>
Flow max_flow(FGraph<Flow> &g, int s, int t, Flow zero = ZERO) {
	int V = g.size();
	Flow flow = zero;
	for (;;) {
		vi d(V, -1);
		queue<int> que;
		d[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (const auto &e : g[v]) {
				if (e.cap <= zero ||  d[e.to] >= 0) continue;
				d[e.to] = d[v] + 1;
				que.push(e.to);
			}
		}
		if (d[t] < 0) return flow;
		vector<int> iter(V, 0);
		Flow f;
		while ((f = augment(g, d, iter, s, t, INF)) > ZERO) flow = flow + f;
	}
}


int num(const string& s, int& p)
{
	assert(isdigit(s[p]));
	int res = 0;
	while (isdigit(s[p]))
	{
		res *= 10;
		res += s[p] - '0';
		p++;
	}
	return res;
}

Poly parse(const string& s)
{
	Poly res(51);
	int n = s.size();
	int p = 0;
	while (p < n)
	{
		int c = 1;
		if (isdigit(s[p]))
		{
			c = num(s, p);
		}
		if (s[p] == 'x')
		{
			p++;
			if (s[p] == '^')
			{
				p++;
				int m = num(s, p);
				res[m] = c;
				p++;
				continue;
			}
			else
			{
				res[1] = c;
				p++;
				continue;
			}
		}
		else
		{
			assert(p == n);
			res[0] = c;
		}
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n, m;
	while (cin >> n >> m, n)
	{
		FGraph<Poly> g(n);
		REP(i, m)
		{
			int a, b; cin >> a >> b; a--; b--;
			string s; cin >> s;
			Poly t = parse(s);
			add_edge(g, a, b, t);
			add_edge(g, b, a, t);
		}
		Poly ans = max_flow(g, 0, n - 1);
		string anss;
		for (int i = 50; i >= 0; i--)
		{
			if (ans[i] > 0)
			{
				if (i > 1)
				{
					if (ans[i] > 1)
					{
						anss += to_string(ans[i]) + "x^" + to_string(i) + "+";
					}
					else
					{
						anss += "x^" + to_string(i) + "+";
					}
				}
				else if (i == 1)
				{
					if (ans[i] > 1)
					{
						anss += to_string(ans[i]) + "x+";
					}
					else
					{
						anss += "x+";
					}
				}
				else if (i == 0)
				{
					anss += to_string(ans[i]) + "+";
				}
			}
		}
		if (anss.size() > 0)
		{
			anss.pop_back();
			cout << anss << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}