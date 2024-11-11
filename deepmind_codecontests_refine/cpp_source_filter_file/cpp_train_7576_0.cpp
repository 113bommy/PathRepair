#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
long long n,p,lcm,tot;
long long arr[100001];
long long num[1000001];
long long power(long long a,long long b){
    long long res=1;
    while (b>0){
        if (b%2==1) res=(res*a)%p;
        b/=2;
        a=(a*a)%p;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    p=1e9+7;
    for (int i=1;i<=n;i++) cin>>arr[i];
    for (long long i=1;i<=n;i++){
        long long cur=arr[i];
        for (long long j=2;j*j<=arr[i];j++){
            long long res=0;
            while (cur%j==0){
                res++;
                cur/=j;;
            }
            num[j]=max(num[j],res);
        }
        if (cur!=1){
            num[cur]=max(num[cur],1);
        }
    }
    lcm=1;
    for (long long i=1;i<=1000000;i++){
        lcm*=power(i,num[i]);
        lcm%=p;
    }
    for (long long i=1;i<=n;i++){
        tot+=lcm*power(arr[i],p-2);
        tot%=p;
    }
    cout<<tot;
}