#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<vector<int>> g(n);
    for(int i=0; i<n-1; ++i) {
        int a, b; cin>>a>>b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> x(n);
    queue<int> q;
    q.push(0); x[0]=1;
    q.push(n-1); x[n-1]=-1;

    while (q.size()) {
        int v=q.front(); q.pop();
        int k=x[v];
        for(int u: g[v]) if (!x[u]) {
            x[u]=k;
            q.push(u);
        }
    }
    int fennec=count(begin(x), end(x), 1);
    int snuke=n-fennec;
    cout<<(fennec>sunuke ? "Fennec" : "Snuke")<<endl;
}
