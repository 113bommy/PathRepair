#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
map<ll,int> t;
int cnt;
const int N=2e5+5;
int n;ll k,a[N]={0},as[N];
int bit[N]={0};
void add(int x,int val) {
    while(x<cnt) bit[x]+=val,x+=x&-x;
}
int sum(int x) {
    int s=0;while(x) s+=bit[x],x-=x&-x;return s;
}
int main() {
    scanf("%d%lld",&n,&k);
    t.clear();
    for(int i=1;i<=n;i++) scanf("%lld",a+i),a[i]-=k,a[i]+=a[i-1],as[i]=a[i];
    ll ans=0;
    sort(as+1,as+1+n);
    cnt=1;
    for(int i=1;i<=n;i++) if(!t.count(as[i])) t[as[i]]=cnt++;
    for(int i=1;i<=n;i++) {
        if(a[i]>=0) ans++;
        ans+=sum(t[a[i]]);
        add(t[a[i]],1);
    }
    printf("%lld\n",ans);
    return 0;
}
