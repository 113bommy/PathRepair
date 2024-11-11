#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n;  cin >> n;
  vector<P> p(n);  rep(i,n) cin >> p[i].second >> p[i].first;
  sort(p.begin(), p.end());
  ll t += 0;
  rep(i,n){
    t += p[i].second;
    if(t > p[i].first){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}