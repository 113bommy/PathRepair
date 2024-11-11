#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  rep(i,n) cin >> p[i].second >> p[i].first;
  sort(p.begin(),p.end());
  ll s = 0;
  rep(i,n){
    s += p[i].second;
    if(s>p[i].first){
      puts("No");
      return 0;
    }
  }
  
  puts("Yes");
}