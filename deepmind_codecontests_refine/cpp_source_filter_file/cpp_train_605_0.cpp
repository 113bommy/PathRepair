#include <bits/stdc++.h>

const int N = 1005; 
const int X = 5005; 

using namespace std;

int n; 
bool f[X], kill; 
int s1[N], s2[N]; 

vector< int > son[N]; 

void dfs(int u) {
	int weight = 0; 
	int size = son[u].size();
	for(int i=0; i<size; ++i) {
		int v=son[u][i]; 
		dfs(v);
		if(kill) return ; 
		weight += s1[v] + s2[v]; 
	}
	for(int i=0; i<=s1[u]; ++i) f[i] = 0; 
	f[0] = 1; 
	for(int i=0; i<size; ++i) {
		int v=son[u][i]; 
		for(int j=s1[u]; j>=0; j--)
			f[j] = (j>=s1[v] && f[j-s1[v]]) || (j>=s2[v] && f[j-s2[v]]);
	}
	bool tmpKill = 1; 
	for(int j=s1[u]; j>=0; j--)
		if(f[j]) {
			weight += s1[u] - j; 
			tmpKill = 0; 
			break; 
		}		 
	if(tmpKill) kill=1; 
	s2[u] = weight - s1[u]; 
}

int main() {
	
	int p; 
	
	cin >> n;
	for(int i=2; i<=n; ++i) cin >> p, son[p].push_back(i);
	for(int i=1; i<=n; ++i) cin >> s1[i];
	
	dfs(1); 
	
	if(kill) printf("IMPOSSIBLE\n");
	else printf("POSSIBLE\n"); 
	
	return 0; 
	
}