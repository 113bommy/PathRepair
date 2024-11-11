#include<bits/stdc++.h>
#define ll long long
const int N=1e4+5;
ll a[N],b[N];
signed main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    ll s1=0,s2=0;
    for (int i=1;i<=n;i++){
        if(a[i]>b[i])s1+=a[i]-b[i];
        if(a[i]<b[i])s2+=(b[i]-a[i])>>1;}
    puts(s1<=s2?"Yes":"No");
    return 0;
}