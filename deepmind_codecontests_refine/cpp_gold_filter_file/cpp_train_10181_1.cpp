#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
pair<int,int> seg[maxn],res[maxn];
int n,m,a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) cin>>seg[i].first>>seg[i].second;
    int lm=0,rm=1e9;
    for (int i=0;i<n;++i){
        lm=max(lm,seg[i].first);
        rm=min(rm,seg[i].second);
    }
    for (int i=0;i<n;++i){
        res[i].first=max(0,seg[i].second-lm+1);
        res[i].second=max(0,rm-seg[i].first+1);
    }
    sort(res,res+n);
    int ans=0;
    a[0]=1e9;
//    for (int i=0;i<n;++i) cout<<res[i].first<<" "<<res[i].second<<endl;
    for (int i=1;i<=n;++i){
        a[i]=min(a[i-1],res[i-1].second);
    }
    for (int i=1;i<n;++i){
        ans=max(ans,a[i]+res[i].first);
    }
    int mxx=0;
    for (int i=0;i<n;++i){
        mxx=max(mxx,seg[i].second-seg[i].first+1);
    }
    cout<<max(ans,mxx+max(rm-lm+1,0))<<endl;
    return 0;
}
