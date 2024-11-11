////////////////////
///   template   ///
////////////////////

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
using namespace std;

//// MACRO ////
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define allof(c) c.begin(), c.end()
#define partof(c,i,n) c.begin() + (i), c.begin() + (i) + (n)
#define EPS 1e-10
#define INF 1000000000

#define countof(a) (sizeof(a)/sizeof(a[0]))
#define PREDIACTE(t,a) [](const t & a) -> bool
#define COMPARISON_T(t) bool(*)(const t &, const t &)
#define COMPARISON(t,a,b) [](const t & a, const t & b) -> bool

//// prime ////
vector<unsigned char> isPrime;
vector<int> primes;
void initPrimes(int n)
{
	isPrime = vector<unsigned char>(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	FOR(i, 2, n + 1)
	{
		if (!isPrime[i]) continue;
		primes.push_back(i);
		for (int j = i * 2; j <= n; j += i)
			isPrime[j] = false;
	}
}

//// Probability ////

// パスカルの三角形(二項定理) 2種類の並べ替えにつかう。
vector<vector<double>> makePascalTriangle(int n, bool probability = false)
{
	typedef vector<double> VD;
	vector<VD> t;
	if (!t.size()) { t.push_back(VD(1, 1)); }
	FOR(i, t.size(), n + 1)
	{
		t.push_back(VD(i + 1));
		REP(j, i)
		{
			double x = t[i - 1][j] * (probability ? 0.5 : 1);
			t[i][j] += x;
			t[i][j + 1] += x;
		}
	}
	return t;
}


//// iota iterator ////
struct iotait
{
	int n;
	iotait(int n = 0) : n(n) { }
	iotait &operator ++() { ++n; return *this; }
	int operator *() { return n; }
};

//// geo ////
struct P3
{
	double x, y, z;
	P3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) { }
	P3 operator +() const { return *this; }
	P3 operator +(const P3 &_) const { return P3(x + _.x, y + _.y, z + _.z); }
	P3 operator -() const { return P3(-x, -y, -z); }
	P3 operator -(const P3 &_) const { return *this + -_; }
	P3 operator *(double _) const { return P3(x*_, y*_, z*_); }
	P3 operator /(double _) const { return P3(x / _, y / _, z / _); }
	double dot(const P3 &_) const { return x*_.x + y*_.y + z*_.z; } // 内積
	P3 cross(const P3 &_) const { return P3(y*_.z - z*_.y, z*_.x - x*_.z, x*_.y - y*_.x); } // 外積
	double sqlength() const { return x*x + y*y + z*z; } // 二乗長さ
	double length() const { return sqrt(sqlength()); } // 長さ
	P3 direction() const { return *this / length(); } // 方向ベクトル
};

struct Sphere
{
	P3 c;
	double r;
	Sphere(double x, double y, double z, double r) : c(x, y, z), r(r) { }
	bool IntersectWith(const Sphere &rhs) { return (c - rhs.c).length() - (r + rhs.r) < EPS; } // 接してても真。
};

//// bit ////
#ifdef _MSC_VER
inline unsigned __builtin_ctz(unsigned x) { unsigned long r; _BitScanForward(&r, x); return r; }
#endif

inline int next_bit_permutation(int x)
{
	int t = x | (x - 1);
	return (t + 1) | (unsigned)((~t & -~t) - 1) >> (__builtin_ctz(x) + 1);
}

//// graph ////
struct Path
{
	int from;
	int to;
	double cost;
	Path(int from = 0, int to = 0, double cost = 0) : from(from), to(to), cost(cost) { }
	bool operator < (const Path &rhs) const { return cost < rhs.cost; }
	bool operator >(const Path &rhs) const { return cost > rhs.cost; }
};



// prim //
pair<double, vector<int>> prim(const vector<vector<double>> &costTable)
{
	int N = costTable.size();
	priority_queue<Path, vector<Path>, greater<Path>> q;
	q.push(Path(0, 0, 0));

	vector<int> parent(N, -1);
	double totalCost = 0;
	while (!q.empty())
	{
		Path cur = q.top(); q.pop();
		int i = cur.to;
		if (parent[i] != -1) continue;
		parent[i] = cur.from;
		totalCost += cur.cost;
		REP(j, N) if (parent[j] == -1) q.push(Path(i, j, costTable[i][j]));
	}
	return make_pair(totalCost, parent);
}

// dijkstra //
pair<vector<double>, vector<int>> dijkstra(const vector<vector<Path>> &routes, int start = 0, int goal = -1)
{
	int N = routes.size();
	priority_queue<Path, vector<Path>, greater<Path>> q;
	q.push(Path(start, start, 0));

	vector<int> prev(N, -1);
	vector<double> cost(N, INF);
	while (!q.empty())
	{
		Path cur = q.top(); q.pop();
		int i = cur.to;
		if (prev[i] != -1) continue;
		prev[i] = cur.from;
		cost[i] = cur.cost;
		if (i == goal) { break; }
		REP(j, routes[i].size())
		{
			Path next = Path(i, routes[i][j].to, cur.cost + routes[i][j].cost);
			if (prev[next.to] == -1)
				q.push(next);
		}
	}
	return make_pair(cost, prev);
}

//// i/o ////
template <class T>
class vevector : public vector<vector<T>>
{
public:
	vevector(int n = 0, int m = 0) : vector<vector<T>>(n, vector<T>(m)) { };
	vevector(int n, int m, const T &initial) : vector<vector<T>>(n, vector<T>(m, initial)) { };
};

template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vevector<T> readjag(int n) { vevector<T> v; REP(i, n) v.push_back(read<T>(read<int>())); return v; }
template <class T> void write(const T &t) { cout << t << endl; }
template <class T> void write(const T &t, const T &t2) { cout << t << ' ' << t2 << endl; }
template <class T> void write(const vector<T> &v)
{
	ostringstream ss;
	for (auto x : v) ss << x << ' ';
	auto s = ss.str();
	cout << s.substr(0, s.length() - 1) << endl;
}

struct _Reader { template <class T> _Reader operator ,(T &rhs) { cin >> rhs; return *this; } };
#define READ(t,...) t __VA_ARGS__; _Reader(), __VA_ARGS__

template <class InIt1, class InIt2>
int partial_compare(InIt1 first1, InIt1 last1, InIt2 first2, InIt2 last2)
{
	return lexicographical_compare(first1, last1, first2, last2) ? -1
		: lexicographical_compare(first2, last2, first1, last1) ? 1
		: 0;
}

//// start up ////
void solve();
int main()
{
	// freopen("A.in", "r", stdin);
	solve();
	return 0;
}

////////////////////
/// template end ///
////////////////////

void dump(unsigned char *pv)
{
	REP(i, 4)
	{
		write(vector<int>(pv + i * 8, pv + i * 8 + 8));
	}
	write("");
}


void solve()
{
	int FREE = 0;

	union BD
	{
		unsigned char stt[32];
		unsigned long long ull[4];
		inline bool operator < (const BD &rhs) const { return lexicographical_compare(ull, ull + 4, rhs.ull, rhs.ull + 4); }
		inline bool operator ==(const BD &rhs) const { return equal(stt, stt + 32, rhs.stt); }
		static BD fromVector(const vector<int> &v) { BD r = {}; copy_n(v.begin(), 32, r.stt); return r; }
		struct hash { size_t operator() (const BD &b) const { return b.ull[0] ^ b.ull[1] ^ b.ull[2] ^ b.ull[3]; } };
	};

	BD goal;
	{
		vector<int> goal_;
		FOR(i, 1, 5) { FOR(j, 1, 8) goal_.push_back(i * 10 + j); goal_.push_back(FREE); }
		goal = BD::fromVector(goal_);
	}

	auto testcases = read<int>();
	REP(testcase, testcases)
	{

		BD initial;
		{
			vector<int> table = read<int>(28);
			table.insert(table.begin() + 0, FREE);
			table.insert(table.begin() + 8, FREE);
			table.insert(table.begin() + 16, FREE);
			table.insert(table.begin() + 24, FREE);

			swap(*find(allof(table), 11), table[0]);
			swap(*find(allof(table), 21), table[8]);
			swap(*find(allof(table), 31), table[16]);
			swap(*find(allof(table), 41), table[24]);

			initial = BD::fromVector(table);
		}

		auto visited = unordered_set<BD, BD::hash>();
		
		int result = -1;

		struct Node { BD bd; int step; };
		queue<Node> q;
		q.push({ initial, 0 });
		while (!q.empty())
		{
			Node cur = q.front(); q.pop();
			if (visited.count(cur.bd) > 0) { continue; }
			visited.insert(cur.bd);
			//dump(cur.bd.stt);

			if (cur.bd == goal) { result = cur.step; break; }
			REP(i, 4)
			{
				BD next = cur.bd;
				auto it = next.stt;
				REP(j, i + 1) it = find(it + 1, next.stt + 32, FREE);
				auto it2 = find(next.stt, next.stt + 32, *(it - 1) + 1);
				if (it2 != next.stt + 32)
				{
					swap(*it, *it2);
					if (visited.count(next) == 0) q.push({ next, cur.step + 1 });
				}
			}
		}

		write(result);
	}

}