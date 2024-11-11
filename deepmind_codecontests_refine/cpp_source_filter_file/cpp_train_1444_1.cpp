#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

ll f(ll b, ll n){
  ll ans = 0;
  while(n > 0){
    ans += n % b;
    n /= b;
  }

  return ans;
}

int main(){
  ll n,s;

  scanf("%lld", &n);
  scanf("%lld", &s);

  ll i = 2;
  int f = 0;
  ll ans;

  if(s > n){
    printf("-1\n");
    return 0;
  }

  if(s == n){
    printf("%lld", n + 1);
    return 0;
  }

  for(i = 2;i*i <= n;i++){
    if(f(i,n) == s){
      printf("%lld\n", i);
      return 0;
    }
  }

  ll t = n - s;
  ll ans = -1;

  for(i = 1;i*i < n;i++){
    ll b = t/i + 1;

    if(b >= 2 && f(b,n) == s) ans = b;
  }

  printf("%lld\n", ans);


  return 0;
}