#include<iostream>
using namespace std;
const int N=100100;
long long n,m,t3,t4,a[N*2],sum;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>t3;
    for(int i=2;i<=n;++i)
    {
        int d,t1,t2;
        cin>>t4;
        t1=t3;t2=t4;
        if(t2<t1) t2+=m;
        d=t2-t1;
        ans+=d;
        if(d>1)
        {
            a[t1+2]++;
            a[t2+1]-=d;
            a[t2+2]+=d-1;
        }    
        t3=t4;
    }
    sum=0;
    for(int i=1;i<=2*m;++i)
    {
        sum+=a[i];
        a[i]=sum;
    }
    sum=0;
    long long maxx=0;
    for(int i=1;i<=2*m;++i)
    {
        sum+=a[i];
        a[i]=sum;
    }
    for(int i=m+1;i<=2*m;++i)
    {
        a[i-m]+=a[i];
        maxx=max(a[i-m],maxx);
    }
    cout<<ans-maxx<<endl;      
    return 0;
}