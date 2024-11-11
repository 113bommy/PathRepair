#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; char c; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	for (;;) {
		int N, M, S, T;
		cin >> N >> M >> S >> T;
		if (!N) break;
		int n = N;
		vector<edge> E;
		while (M--) {
			int x, y; string s;
			cin >> x >> y >> s;
			vector<int> a;
			a.push_back(x);
			for (int i = 0; i < s.length() - 1; i++)
				a.push_back(n++);
			a.push_back(y);
			for (int i = 0; i < s.length(); i++)
				E.push_back(edge{a[i], a[i + 1], s[i]});
		}
		int m = E.size();
		vector<bool> pos(n);
		pos[T] = true;
		for (int t = 0; t < n; t++)
			for (int i = 0; i < m; i++)
				if (pos[E[i].v])
					pos[E[i].u] = true;
		if (!pos[S]) {
			cout << "NO" << endl;
			continue;
		}
		vector<vector<edge> > EE(26);
		for (int i = 0; i < m; i++)
			EE[E[i].c - 'a'].push_back(E[i]);
		string s;
		vector<bool> a(n);
		a[S] = true;
		int t;
		for (t = 0; t < n; t++) {
			if (a[T]) break;
			vector<bool> _a(n);
			char c;
			for (c = 'a'; c <= 'z'; c++) {
				vector<edge> E = EE[c - 'a'];
				bool ok = false;
				for (int i = 0; i < E.size(); i++)
					if (E[i].c == c && a[E[i].u] && pos[E[i].v]) {
						_a[E[i].v] = true;
						ok = true;
					}
				if (ok) break;
			}
			s.push_back(c);
			a = _a;
		}
		if (t == n) cout << "NO" << endl;
		else cout << s << endl;
	}
}