x#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n;i++)
using namespace std;
#define int long long
signed main(){
    int n,k;
    typedef pair<int,int> pii;
    cin>>n>>k;
    vector<bool>flag(n+1,true);
    vector<bool>IsPrint(n+1,true);
    vector<pii>mp(n+1);
    int ans=0;
    rep(i,n){
        int temp; cin>>temp;
        if(temp==0){ans++; mp[i+1]=pii(0,0);flag[i+1]=false; continue;}
        mp[i+1]=pii(temp,mp[temp].second+1);
        flag[temp]=false;
    }
    vector<int>yebi;
    vector<int>dp(n+1,0);
    rep(i,n)if(flag[i+1])yebi.push_back(i+1);
    rep(z,yebi.size()){
        int i=yebi[z];
        ans++;
        IsPrint[i]=false;
        flag[i]=false;
        pii next=mp[i];
        for(int i=1;i<=k-1;i++){
            if(mp[next.first].second==0)break;
            if(IsPrint[next.first]==false){
                if(dp[next.first]>=k-1-i)break;
                dp[next.first]=max(dp[next.first],k-1-i);
                IsPrint[next.first]=false;
                next=mp[next.first];
                continue;
            }
            IsPrint[next.first]=false;
            flag[next.first]=false;
            ans++;
            next=mp[next.first];
        }
    }
    cout<<ans<<endl;
}
