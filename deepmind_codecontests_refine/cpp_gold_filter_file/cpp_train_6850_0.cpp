#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n*3);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v, u--, v--;
        for(int j = 0; j < 3; j++){
            g[u*3 + j].push_back(v*3 + (j+1)%3);
        }
    }
    int s, t;
    cin >> s >> t, s--, t--;

    queue<int> q;
    q.push(s*3);
    vector<int> dist(n*3, -1);
    dist[s*3] = 0;
    while(!q.empty()){
        int a = q.front(); q.pop();
        for(auto& e : g[a]){
            if(dist[e] != -1) continue;
            dist[e] = dist[a] + 1;
            q.push(e);
        }
    }
    cout << (dist[t*3] % 3 == 0 ? dist[t*3] / 3 : -1) << endl;
    return 0;
}