#include<bits/stdc++.h>
using namespace std;
long long a[100005],sum[100005],n,m,ans;
long long check(long long x){
    long long res=0;
    for(int i=1;i<=n;i++){
        int k=lower_bound(a+1,a+1+n,x-a[i])-a-1;
        res+=n-k;
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long l=0,r=200001,res=0;
    while(r>=l){
        long long mid=(l+r)/2;
        if(check(mid)>=m) l=mid+1;
        else r=mid-1; 
    }
    for(int i=1;i<=n;i++){
        int k=lower_bound(a+1,a+1+n,l-1-a[i])-a-1;
        res+=n-k;
        ans+=sum[n]-sum[k]+(n-k)*a[i];
    }
    ans+=(m-res)*(l-1);
    cout<<ans<<endl;
}