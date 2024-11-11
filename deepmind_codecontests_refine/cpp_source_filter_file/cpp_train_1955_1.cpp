#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
int main(){
   int N; cin >> N;
   int nb[52][52];
   ll ans = 0;
   memset(nb, 0, sizeof nb);
   vector<pair<int,int>> v;
   for (int i = 0; i < N; i++) {
      string d; cin >> d;
      ll num = llround(d*1e9);
      int a, b; a = b = 0;
      while (num%2 == 0) {
         num/= 2;
         a++;
      }
      while (num%5 == 0) {
         num/= 5;
         b++;
      }
      v.push_back({a,b});
      for (int j = 0; j <= a; j++) {
         for (int k = 0; k <= b; k++) {
            nb[j][k]++;
         }
      }
   }
   for (int i = 0; i < N; i++) {
      int a = v[i].first, b = v[i].second;
      ans+= nb[max(18-a,0)][18-b];
      if (a > 8 && b > 8)
         ans--;
   }
   cout << ans/2;
}