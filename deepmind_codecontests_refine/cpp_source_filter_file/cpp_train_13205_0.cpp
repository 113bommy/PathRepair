#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a, b;
vector<ll> v;


ll comb(ll n, ll m){
 ll ret = 1;
 for(ll i=1;i<=m;i++) ret = ret * (n-m+i) / i;
 return ret;
}

int main(void){
 cin >> n >> a >> b;
 for(int i=0;i<n;i++) {ll tmp; cin >> tmp; v.push_back(-tmp);}
 sort(v.begin(), v.end());
 ll thesum = 0;
 for(int i=0;i<a;i++) thesum += (-v[i]);
 printf("%.7f\n",((double)(thesum)) / a);
 ll ans = 0; 
 if (v[0]==v[a-1]){
  int i;
  for(i=a-1;i<n;i++) if (v[0] != v[i]) break;
  int m = i;
  for(int i=a;i<=min(m,b);i++) ans += comb(m,i);
 }else{
  int mi, ma;
  for(mi=0;mi<n;mi++) if (v[mi]==v[a-1]) break;
  for(ma=a-1;ma<n;ma++) if (v[ma]!=v[a-1]) break;
  int m = ma - mi;
  ans += comb(m, a-mi);
 }
 cout << ans << endl;
 return 0;
}