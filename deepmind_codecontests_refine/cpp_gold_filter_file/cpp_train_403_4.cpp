#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
  int n;
  while(cin >> n, n){
    vector<pll> a(n);
    rep(i,n)cin >> a[i].second >> a[i].first;
    sort(all(a));

    bool ans = true;
    ll sum = 0;
    rep(i,n){
      sum += a[i].second;
      if(sum > a[i].first) ans = false;
    }
    cout << (ans?"Yes":"No") << endl;
  }
}