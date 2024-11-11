#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int inf = 100000 * 10000 + 100;

int main(){
	int V, E, r;
	cin >> V >> E >> r;
	vector<int> cost(V, inf);
	cost[r] = 0;
	vector<int> s(E);
	vector<int> t(E);
	vector<int> d(E);
	for(int i = 0; i < E; i++){
		cin >> s[i] >> t[i] >> d[i];
	}
	
	for(int i = 0; i < V; i++){
		bool update = false;
		for(int j = 0; j < E; j++){
			if(cost[s[j]] < inf && cost[s[j]] + d[j] < cost[t[j]]){
				cost[t[j]] = cost[s[j]] + d[j];
				update = true;			}
		}
		if (!update) break;
	}
	for(int i = 0; i < V; i++){
		if(cost[i] < inf)
			cout << cost[i] << endl;
		else
			cout << "INF" << endl;
	}
}