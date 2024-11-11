#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<ll, int> pp;

typedef struct {
	int to;
	ll cost;
} edge;

void Dijk(int s, vector<vector<edge>> &d, vector<ll> &ans) {
	int i;
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, s));
	while (!que.empty()) {
		int n = que.top().second;
		ll c = que.top().first;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			vector<edge>& e = d[n];
			rep(i, e.size()) {
				if (ans[e[i].to] == INF) {
					que.push(pp(e[i].cost + c, e[i].to));
				}
			}
		}
	}
}

int main(void) {
	int num, i, m, s, g, x, y, c, d;
	ll sum = 1e15;
	cin >> num >> m >> s >> g;
	vector<vector<edge>> a(num + 1), b(num + 1);
	vector<ll> fir(num + 1, INF), lat(num + 1, INF), ans(num + 1);
	priority_queue<ll> que;
	rep(i, m) {
		scanf("%d%d%d%d", &x, &y, &c, &d);
		a[x].push_back({ y, c });
		a[y].push_back({ x, c });
		b[x].push_back({ y, d });
		b[y].push_back({ x, d });
	}
	Dijk(s, a, fir);
	Dijk(g, b, lat);
	for (i = num; i > 0; i--) {
		que.push(sum - fir[i] - lat[i]);
		ans[i] = que.top();
	}
	for (i = 1; i <= num; i++)
		cout << ans[i] << "\n";
	return 0;
}