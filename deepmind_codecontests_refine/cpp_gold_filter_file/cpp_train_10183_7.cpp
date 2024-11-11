#include<bits/stdc++.h>
using namespace std;

bool used[101010];
int main(){
    int n,k;
    cin>>n>>k;
    pair<int,int> a[n];
    for(int i=0;i<n;i++)cin>>a[i].second>>a[i].first;
    sort(a,a+n);
    reverse(a,a+n);

    priority_queue<int,vector<int>,greater<int>> que;
    long long cnt=0, sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i].first;
        if(!used[a[i].second]){
            ++cnt;
            used[a[i].second]=true;
        }
        else que.push(a[i].first);
    }
    long long ans=sum+cnt*cnt;
    for(int i=k;i<n;++i){
        if(cnt>=k)break;
        if(used[a[i].second])continue;
        ++cnt;
        used[a[i].second]=true;
        int mini=que.top();que.pop();
        sum-=mini;
        sum+=a[i].first;
        ans=max(ans,sum+cnt*cnt);
    }
    cout<<ans<<endl;
    return 0;
}
