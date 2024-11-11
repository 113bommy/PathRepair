#include <bits/stdc++.h>
using namespace std;
#define MAX 1000010
#define mod 1000000007
typedef long long ll;
int n,f[MAX],ad;

int main()
{
    scanf("%d",&n);
    f[n]=n;
    f[n-1]=(ll)n*n%mod;
    for(int i=n-2;i>=1;--i)
    {
        ad=(ad+f[i+3])%mod;
        f[i]=f[i+1];
        f[i]=(f[i]+(ll)(n-1)*(n-1)%mod)%mod;
        f[i]=(f[i]+add)%mod;
        f[i]=(f[i]+i+1)%mod;
    }
    printf("%d\n",f[1]);
}