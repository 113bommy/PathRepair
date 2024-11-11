#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAX_N = 1e4 + 10;

class Edge{
public:
	int t, w;
	Edge(){}
	Edge(int t, int w): t(t), w(w) {}
};

vector<Edge> G[MAX_N];
int H[MAX_N][MAX_N];
int n, h[MAX_N];

int height(int s, int idx){
	Edge e = G[s][idx];
	if (H[s][e.t]>=0) return H[s][e.t];
	H[s][e.t] = e.w;
	int u = e.t;
	for (int i = 0; i < G[u].size(); ++i)
	{
		if (G[u][i].t == s) continue;
		H[s][u] = max(H[s][u], height(u, i)+e.w);
	}
	return H[s][u];
}



int main(int argc, char const *argv[])
{
	int s, t, w;
	cin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> s >> t >> w;
		G[s].push_back(Edge(t, w));
		G[t].push_back(Edge(s, w));
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < G[i].size(); ++j) H[i][G[i][j].t] = -1;
	}

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < G[i].size(); ++j)
    	{
    		Edge e = G[i][j];
    		if (H[i][e.t] < 0) H[i][e.t] = height(i, j);
    	}
    }

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < G[i].size(); ++j) h[i] = max(h[i], H[i][G[i][j].t]);
    }

	for (int i = 0; i < n; ++i) cout << h[i] << endl;
	return 0;
}
