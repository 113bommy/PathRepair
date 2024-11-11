#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> g[8];

int dfs(int v,int x) {
    if (x==(1<<n)-1)
        return 1;
    int c=0;
    for (int u:g[v]) {
        if (~x&1<<u)
            c+=dfs(u,x|1<<u);
    }
    return c;
}

int main() {
    int m;
    cin>>n>>m;
    while (m--) {
        int v,u;
        cin>>v>>u;
        v--,u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    cout<<dfs(0,1)<<endl;
    return 0;
}