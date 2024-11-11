#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

class Edge
{
public:
    int to, cost;
    Edge(){};
    Edge(int to0, int cost0){to = to0; cost = cost0;}
};

void shortestPath(const vector<vector<Edge> >& edges, int start, vector<int>& dist)
{
    dist.assign(edges.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0, start));

    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        int v = p.second;
        if(dist[v] < p.first)
            continue;
        for(unsigned i=0; i<edges[v].size(); ++i){
            Edge e = edges[v][i];
            if(dist[v] + e.cost < dist[e.to]){
                dist[e.to] = dist[v] + e.cost;
                q.push(make_pair(dist[e.to], e.to));
            }
        }
    }
}

int main()
{
	for(;;){
		int m, n, k, d;
		cin >> m >> n >> k >> d;
		if(m == 0)
			return 0;

		vector<int> cake(m);
		for(int i=0; i<m; ++i)
			cin >> cake[i];

		vector<vector<Edge> > edges((m+n+2)*(1<<m));
		while(--d >= 0){
			vector<string> s(2);
			int cost;
			cin >> s[0] >> s[1] >> cost;
			cost *= k;

			vector<int> a(2);
			for(int i=0; i<2; ++i){
				if(s[i][0] == 'H')
					a[i] = 0;
				else if(s[i][0] == 'C')
					a[i] = s[i][1] - '0';
				else if(s[i][0] == 'L')
					a[i] = atoi(s[i].substr(1).c_str()) + m;
				else
					a[i] = m+n+1;
			}

			for(int k=0; k<2; ++k){
				for(int i=0; i<(1<<m); ++i){
					if(1 <= a[1] && a[1] <= m && (i & (1<<(a[1]-1))))
						continue;
					if(1 <= a[1] && a[1] <= m && !(i & (1<<(a[1]-1)))){
						int j = i | (1<<(a[1]-1));
						edges[i*(m+n+2)+a[0]].push_back(Edge(j*(m+n+2)+a[1], cost-cake[a[1]-1]));
					}else
						edges[i*(m+n+2)+a[0]].push_back(Edge(i*(m+n+2)+a[1], cost));
				}
				swap(a[0], a[1]);
			}
		}

		vector<int> dist;
		shortestPath(edges, 0, dist);
		int ret = INT_MAX;
		for(int i=0; i<(1<<m); ++i)
			ret = min(ret, dist[(m+n+2)*(i+1)-1]);
		cout << ret << endl;
	}
}