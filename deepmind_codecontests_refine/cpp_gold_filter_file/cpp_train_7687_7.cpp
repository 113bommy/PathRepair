#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<bool>> graph(n,vector<bool> (n,false));
  for(int i = 0; i < m ; ++i){
    int a,b;
    cin >> a>>b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }
  vector<int> v(n);
  for( int i = 0; i<n; ++i) v[i] = i;
  int ans = 0;
  do{
    bool ok = true;
    for( int i = 1;i < n;++i) if(graph[v[i-1]][v[i]] == false) ok = false;
    if(ok) ans++;
    } while ( next_permutation(++v.begin(),v.end()));
  cout << ans << endl;
}