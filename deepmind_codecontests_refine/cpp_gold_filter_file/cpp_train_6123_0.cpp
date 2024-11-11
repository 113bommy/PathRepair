#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
vector<int> G[maxn];
typedef long long LL;
const LL mod = 1000000007;
LL f[2][maxn];
void DFS(int u, int fa = 0){
	f[0][u] = f[1][u] = 1;
	for(int v : G[u]) if(v != fa){
		DFS(v, u);
		f[0][u] = f[0][u] * f[1][v] % mod;
		f[1][u] = f[1][u] *(f[0][v] + f[1][v]) % mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for(int i = 1; i < N; i += 1){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1);
	cout << (f[0][1] + f[1][1]) % mod;
}