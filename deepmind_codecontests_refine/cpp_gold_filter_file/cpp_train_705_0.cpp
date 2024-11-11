#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll ;

int main (){
  int n,m;
  cin >> n >> m;
  vector<int>s[m];
  rep(i,m){
    int k;
    cin >> k;
    rep(j,k){
      int t;
      cin >> t;
      t--;
      s[i].push_back(t);
    }
  }
  int p[m];
  rep(i,m)cin >> p[i];
  int ans=0;
  for(int i=0;i<pow(2,n);i++){
    bool ok = 1;
    rep(mm,m){
      int a = 0;
      for(int l:s[mm]){
        if(i & (1<<l))a += 1;
      }
      if(a%2!=p[mm])ok = 0;
    }
    if(ok==1)ans += 1;
  }
  cout << ans << endl;
  return 0;
}
