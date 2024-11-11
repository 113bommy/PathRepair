#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n,m;
    cin>>n>>m;
    array<int,2> d[n];
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        d[i] = {a[i],i};
    }
    sort(d,d+n);
    vector<vector<array<int,2>>> v(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    int c[n];
    for(int i=0;i<n;i++) c[i] = -1;
    int ans[m];
    int INF = 1e9;
    for(int i=0;i<m;i++) ans[i] = INF;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    q.push({d[0][0],d[0][1]});
    bool used[n];
    for(int i=0;i<n;i++) used[i] = 0;
    while(q.size()){
        array<int,2> p = q.top();
        //cerr << p[0] << " " << p[1] << endl;
        q.pop();
        used[p[1]]=1;
        if(c[p[1]]==-1) c[p[1]] = 1;
        for(auto i:v[p[1]]){
            if(c[i[0]]==-1) c[i[0]] = c[p[1]] ^ 1;
            ans[i[1]] = max(a[i[0]], p[0]);
            if(!used[i[0]]){
                used[i[0]]=1;
                q.push({a[i[0]],i[0]});
            }
        }
    }
    for(int i=0;i<n;i++){
        bool pos = false;
        for(auto j:v[i]){
            int p = j[0];
            int itr = j[1];
            if(c[p] == c[i]) continue;
            if(ans[itr] < a[i]){
                cout << -1 << endl;
                return 0;
            }
            if(ans[itr] == a[i]) pos = 1;
        }
        if(!pos){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(c[i] == 1) cout << "W";
        else cout << "B";
    }
    cout << "\n";
    for(int i=0;i<m;i++){
        cout << ans[i] << "\n";
    }
}