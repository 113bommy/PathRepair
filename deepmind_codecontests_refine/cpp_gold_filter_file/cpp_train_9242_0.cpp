#include <stdio.h>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;
int n,k,a[200200];
long long inv[200200]={0,1},fact[200200]={1,1},ifact[200200]={1,1};

int main()
{
  scanf ("%d %d",&n,&k);
  for (int i=0;i<n;i++) scanf ("%d",&a[i]);
  
  for (int i=2;i<200200;i++){
inv[i] = (mod - mod / i) * inv[mod % i]%mod;
    fact[i] = fact[i-1] * i % mod;
    ifact[i] = ifact[i-1] * inv[i]%mod;
  }
  
  sort(a,a+n);
  long long ans = 0;
  for (int i=k-1;i<n;i++){
    long long c = fact[i] * ifact[k-1] % mod * ifact[i-k+1]%mod;
ans = (ans + mod + c*(a[i]-a[n-i-1])%mod) % mod;
  }
  printf ("%lld\n",ans);
return 0;
}
