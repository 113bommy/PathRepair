#include <bits/stdc++.h>

using namespace std;

#define K 600001
#define FOE(i, s, t) for (int i = s; i <= t; i++)

vector<int> nxt[K];
int n;

int dfs[K];
vector<int> ans1, ans2;

void DFS(int u, int f){
	if (f) ans2.push_back(u);
	else ans1.push_back(u);
	dfs[u] = 1;
	for (auto Z : nxt[u]) if (!dfs[Z]) {DFS(Z, f); return;}
}

int main(){
	int cx, cy;
	scanf("%d%d", &n, &m);
	FOE(i, 1, m){
		int s, t; scanf("%d%d", &s, &t);
		nxt[s].push_back(t);
		nxt[t].push_back(s);
		cx = s; cy = t;
	}
	
	dfs[cy] = 1;
	DFS(cx, 0);
	DFS(cy, 1);
	printf("%lu\n", ans1.size() + ans2.size());
	for (int i = ans1.size() - 1; i >= 0; i--) printf("%d ", ans1[i]);
	for (int i = 0; i < ans2.size(); i++) printf("%d%c", ans2[i], (i == ans2.size() - 1?'\n':' '));
}

