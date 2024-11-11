#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n,k;
   cin >> n >> k;
   vector<int> P(n),C(n);
   rep(i,n) cin >> P[i];
   rep(i,n) cin >> C[i];
   rep(i,n) P[i]--;
   ll ans = -1e18;
   rep(si,n){
      int x = si;
      vector<int> s;
      ll tot=0;
      while(1){
         x=P[x];
         s.push_back(C[x]);
         tot += C[x]; 
         if(x==si) break;
      }
      int l = s.size();
      ll t = 0;
      rep(i,l){
         t += s[i];
         if (i+1 > k) break;
         ll now = t;
         if (tot > 0){
            ll e = (k-(i+1))/l;
            now += e*tot;
         }
         ans = max(ans,now);
      }
   }
   cout << ans << endl;
   return 0;  
}