#include <bits/stdc++.h>
using namespace std;
vector<int> e[1000500];
int p[1000500];
int n;
void link(int a,int b) 
{
	e[a].push_back(b);
	e[b].push_back(a);
}

void dfs(int u,int fa) 
{
    for (int i=0;i<e[u].size();i++) 
	{
        int v=e[u][i]; 
		if (v==fa) continue;
        dfs(v,u);
    }
    if (!p[u] && !p[fa]) p[u] = p[fa] = 1; 
}

int main() {
    cin>>n;
    for (int i=1;i<n;i++) 
    {
    	int x,y;
    	cin>>x>>y;
    	link(x,y);
    }
    p[0] = 1;
    dfs(1,0);
    int ans = 1;
    for (int i=1;i<=n;i++) if (!p[i]) ans = 0;
    puts(!ans?"First":"Second");
    return 0;
}