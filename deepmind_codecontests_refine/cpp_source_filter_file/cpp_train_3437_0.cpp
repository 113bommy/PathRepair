#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX_NODE 10000
#define INF 1000000000

using namespace std;

struct Edge {int to, w;};
typedef pair<int, int> PII;

vector<Edge> adj[MAX_NODE];
int d[MAX_NODE];

void dijkstra(int n, int start) {
	priority_queue<PII, vector<PII>, greater<PII>> que;
	fill(d, d + n, INF);

	d[start] = 0;
	que.emplace(0, start);
	while (!que.empty()) {
		PII p = que.top();
		que.pop();
		int from = p.second;

		if (d[from] < p.first)
			continue;

		for (auto& e : adj[from])
			if (d[from] + e.w < d[e.to]) {
				d[e.to] = d[from] + e.w;
				que.emplace(d[e.to], e.to);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		while (k--) {
			int v, c;
			cin >> v >> c;
			adj[u].push_back(v, c);
		}
	}

	dijkstra(n, 0);

	for (int i = 0; i < n; i++)
		cout << i << " " << d[i] << endl;

	return 0;
}