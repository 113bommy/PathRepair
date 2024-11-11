#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxN = 1e5 + 5; 
vector<int> sons[maxN];
int N, l[maxN], e, pre[maxN], q1[maxN], q2[maxN], ed, q[maxN];
bool caterpillar[maxN];
struct edge{
	int v, fa;
}G[maxN << 1];
void add(int u, int v) {
	G[e].v = v; G[e].fa = l[u]; l[u] = e++;
}
int dfs(int u, int fa, int& ans) {
	ans = u; int maxx = 0; pre[u] = 0;
	for(int i = l[u]; i != -1; i = G[i].fa) {
		int v = G[i].v;
		if(v == fa) continue; 
		int tmp, t;
		if((t = dfs(v, u, tmp)) + 1 > maxx) 
		maxx = t + 1, ans = tmp, pre[u] = v;
	}
	return maxx;
}
int solve(int u, int* f) {
	int tot = 0;
	for(int k = 1; k <= ed; ++k) {
		int i = q[k];
		//cout <<i<<"**"<<endl; 
		int sz = 0;
		for(int j = l[i]; j != -1; j = G[j].fa) 
			if(!caterpillar[G[j].v]) sz++;
		int tmp = tot;
		for(int j = 1; j <= sz; ++j) f[++tot] = tmp + j + 1;
		f[++tot] = tmp + 1;
	}
	return tot;
}
bool cmp() {
	for(int i = 1; i <= N; ++i) {
		if(q1[i] < q2[i]) return 1;
		if(q1[i] > q2[i]) return 0;
	}
	return 1;
}
int main() {
	scanf("%d", &N); 
	for(int i = 1; i <= N; ++i) l[i] = -1;
	for(int i = 1; i < N; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	int u, v;
	dfs(1, -1, u); dfs(u, -1, v);
	//cout <<u<<' '<<v<<endl; 
	for(int i = u; i; i = pre[i]) caterpillar[i] = 1, q[++ed] = i;
	if(solve(u, q1) < N) {
		printf("-1\n");
		return 0;
	} 
	for(int i = 1; i * 2 <= ed; ++i) swap(q[i], q[ed - i + 1]);
	solve(v, q2);
	if(cmp()) {
		for(int i = 1; i <= N; ++i) printf("%d ", q1[i]);
	} else for(int i = 1; i <= N; ++i) printf("%d ", q2[i]);
	return 0;
}