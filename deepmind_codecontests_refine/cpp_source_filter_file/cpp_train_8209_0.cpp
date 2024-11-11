#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>

#define X first
#define Y second
#define MP make_pair
typedef long long ll;
using namespace std;
const int MAX = 101;

int root[101];
int ranks[101];

struct E{
	E(int from, int to, int cost):from(from), to(to), cost(cost){}
	int from, to, cost;
	bool operator < (const E & e){
		return cost < e.cost;
	}
};

void Init(){
	for(int i = 0; i < MAX; i++){
		root[i] = i;
		ranks[i] = 1;
	}
}

int find(int x){
	if(root[x] == x) return x;
	else return root[x] = find(root[x]);
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(ranks[x] < ranks[y]){
		root[x] = y;
	}else{
		root[y] = x;
		if(ranks[x] == ranks[y]) ranks[x]++;
	}
}

int main(){
	int n, m;
	while(cin >> n && n != 0){
		cin >> m;
		Init();
		vector<E> tb;
		for(int i = 0; i < m; i++){
			int a, b, cost;
			scanf("%d,%d,%d", &a, &b, &cost);
			tb.push_back(E(a, b, cost));
		}

		sort(tb.begin(), tb.end());

		int ans = 0;
		for(int i = 0; i < tb.size(); i++){
			if(find(tb[i].from) != find(tb[i].to)){
				ans += (tb[i].cost/100) - 1;
				unite(tb[i].from, tb[i].to);
			}
		}

		cout << ans << endl;
	}
	return 0;
}