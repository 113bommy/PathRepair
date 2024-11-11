#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> jobs[m];
  
  rep(i,n){
    int a,b;
    cin >> a >> b;
    if(a>m)continue;
    jobs[m-a].push_back(b);
  }
  priority_queue<int> p;
  ll ans = 0;
  for(int i=m-1;i>=0;i--){
    for(int j : jobs[i]){
      p.push(j);
    }
    if(!p.empty()){
      ans += p.top();
      p.pop();
    }
  }
  cout << ans << endl;
}
