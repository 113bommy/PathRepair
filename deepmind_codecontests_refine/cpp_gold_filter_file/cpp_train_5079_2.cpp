#include <bits/stdc++.h>
using namespace std;
long long int sum[200005];
int main(){
    long long int n,d,a;
    cin >> n >> d >> a;
    pair<int,long long int> p[n];
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
        p[i].second = (p[i].second+a-1)/a;
    }
    sort(p,p+n);
    int r[n];
    int tmp=n-1;
    for(int i=n-1;i>=0;i--){
        while(p[tmp].first+2*d>=p[i].first && tmp>=0)tmp--;
        r[i]=tmp+1;
    }
    long long int ans=0;
    for(int i=0;i<n;i++){
        p[i].second-=(sum[i]-sum[r[i]]);
        sum[i+1]=sum[i]+max(0LL,p[i].second);
        ans+=max(0LL,p[i].second);
    }
    cout << ans << endl;
}