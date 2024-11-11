#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

ll N, M, color[100001], A, B, C;
vector<int> G[100001];

bool dfs(int now, int c){
	color[now] = c;
	for(int i=0; i<G[now].size(); i++){
		if(color[G[now][i]] != -1){
			if(color[G[now][i]] == c) return false;
			continue;
		}else{
			if(!dfs(G[now][i], 1-c)) return false;
		}
	}
	return true;
}

void dfs2(int now){
  color[now] = 1;
  for(not i=0; i<G[now].size(); i++){
    if(color[G[now][i]] == -1)
      dfs2(G[now][i]);
  }
  return;
}

int main(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0; i<N; i++) color[i] = -1;
	for(int i=0; i<N; i++){
		if(!G[i].size()) A++;
		else{
			if(color[i] != -1) continue;
			if(dfs(i, 0)) B++;
			else{C++;
                       dfs2(i);

                    }
		}
	}
	ll ans = 2*B*B + A*A + 2*A*(N-A) + 2*B*C + C*C;
	cout << ans << endl;
	return 0;
}