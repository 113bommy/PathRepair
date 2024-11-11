#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
ll sum[N],d[N],a[N],n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
	{
        if(i%2==0) sum[i]=sum[i-1]+a[i];
        else sum[i]=sum[i-1];
    }
    for(int i=2;i<=n;i++)
	{
        if(i%2==1) d[i]=max(d[i-2]+a[i],d[i-1]);
        else d[i]=max(d[i-2]+a[i],sum[i-1]);
    }
    cout<<d[n]<<endl;
    return 0;
}