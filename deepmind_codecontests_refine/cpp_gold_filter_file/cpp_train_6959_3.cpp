#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main(void){
 cin >> n;
 int ans = 100;
 for(ll i=1;i*i<=n;i++){
  if (n%i==0) ans = min(ans, (int)(to_string(max(i, n/i)).size()));
 }
 cout << ans << endl;
 return 0;
}