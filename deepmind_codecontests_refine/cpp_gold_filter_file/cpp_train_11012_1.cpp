#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef pair <int,int> pii;
int N, M;
vector <pii> bomb;
vector <pii> edge[200005];
int xors[100005];
bool vis[100005];
vector <int> lists;

int dfs(int v){
    vis[v] = true;
    int ans = xors[v];
    for (pii e: edge[v]){
        if (!vis[e.first]){
            int res = dfs(e.first);
            if (res == 1){
                lists.push_back(e.second);
            }
            ans ^= res;
        }
    }
    return ans;
}

bool cmp(pii a, int b){
    return a.first < b;
}

int main() {
    cin >> N >> M;
    int a, b;
    for (int i=0; i<N; i++){
        scanf("%d %d", &a, &b);
        bomb.push_back({a,b});
    }
    sort(bomb.begin(), bomb.end());
    int l, r;
    for (int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        l = lower_bound(bomb.begin(), bomb.end(), a, cmp) - bomb.begin();
        r = lower_bound(bomb.begin(), bomb.end(), b+1, cmp) - bomb.begin();
        edge[l].push_back({r, i+1});
        edge[r].push_back({l, i+1});
    }
    xors[0] = bomb[0].second;
    for (int i=1; i<N; i++){
        xors[i] = bomb[i-1].second ^ bomb[i].second;
    }
    xors[N] = bomb[N-1].second;
    memset(vis, false, sizeof(vis));
    for (int i=0; i<N; i++){
        if (!vis[i]){
            int res = dfs(i);
            if (res == 1){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << lists.size() << endl;
    sort(lists.begin(), lists.end());
    for (int q: lists){
        printf("%d ", q);
    }
    cout << endl;
    return 0;
}
