#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n, m, a;
  cin>>n>>m;
  priority_queue<int> q;
  while(n--) cin>>a, q.push(a);
  while(m--) q.push(q.top()/2), q.pop();
  int res = 0;
  while(!q.empty()) res += q.top(), q.pop();
  cour<<res<<endl;
}