#include<bits/stdc++.h>
using namespace std;
long long f[100009], ef[100009], depe[100009], pas[100009];
vector<long long> ve[123456];
long long M;
void deefes(long long x){
    ef[x] = 1;
    depe[x] =1;
    for(auto y : ve[x]){
        if(ef[y]) continue;
        deefes(y);
        depe[x] = depe[x] * depe[y] % M;
    }
    depe[x] ++;
}
void dfs(long long x, long long ze){
    f[x] = 1;
    pas[x] = ze;
    vector<pair<long long,long long> > v;
    for(auto y : ve[x]){
        if(f[y]) continue;
        v.push_back({y, depe[y]});
        pas[x] = pas[x] * depe[y] % M;
    }
    if(v.size() == 0) return;
    v.push_back({-1, ze});
    vector<long long> pre(v.size()+2);
    vector<long long> suf(v.size()+2);
    pre[0] = 1;
    for(long long i = 0; i < v.size(); i++)
        pre[i+1] = pre[i] * v[i].second % M;
    suf[v.size() + 1] = 1;
    for(long long i = v.size(); i >= 1; i--)
        suf[i] = suf[i + 1] * v[i - 1].second % M;
    for(long long i =0 ; i < v.size() - 1; i++){
        dfs(v[i].first, (pre[i] * suf[i + 2]  + 1) % M);
    }

}
pair<long long,long long> x[100009];
 int main(){
    long long n;
    cin >> n >> M;
    for(long long i = 0; i < n - 1; i ++){
        long long a, b;
        cin >> a >> b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    deefes(1);
    dfs(1, 1);
    for(long long i = 1; i <= n; i++)
        cout << pas[i] << endl;
}
