#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define per(i,l,r) for (int i=l;i>=r;i--)
using namespace std;
typedef long long ll;
int n,x,ans;
int a[400500],st[400500];
map<int,int> c;
bool jud(int mid){
    int now=mid;
    c.clear();
    int tot=0;
    rep(i,2,n){
        if (a[i]>a[i-1]) continue;
        while (tot&&st[tot]>a[i]){
            c[st[tot]]=0;
            tot--;
        }
        st[++tot]=a[i];
        int x=a[i];
        c[x]++;
        if (mid==1) return 0;
        while (c[x]>=mid) c[x]=0,c[--x]++;
        if (x<=0) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int l=1,r=n,ans=n;
    while (l<=r){
        int mid=(l+r)/2;
        if (jud(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}