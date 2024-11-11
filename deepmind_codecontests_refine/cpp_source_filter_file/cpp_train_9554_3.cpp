#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=3e5+5;
pair<int,int>p[maxm];
int r[maxm],c[maxm];
int n,m,k;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        p[i]={x,y};
        r[x]++,c[y]++;
    }
    int ma1=-1,num1=0;
    for(int i=1;i<=n;i++)ma1=max(ma1,r[i]);
    for(int i=1;i<=n;i++)num1+=(r[i]==ma1);
    int ma2=-1,num2=0;
    for(int i=1;i<=m;i++)ma2=max(ma2,c[i]);
    for(int i=1;i<=m;i++)num2+=(c[i]==ma2);
    int cnt=0;
    for(int i=1;i<=k;i++){
        int x=p[i].first,y=p[i].second;
        cnt+=(r[x]==ma1&&c[y]==ma2);
    }
    cout<<ma1+ma2-(cnt==num1*num2)<<endl;
    return 0;
}
