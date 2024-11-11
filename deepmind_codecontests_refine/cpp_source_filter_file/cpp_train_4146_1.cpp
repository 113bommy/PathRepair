#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n,ans=0;
    cin>>n;
    vector<int> A(n);
    map<int,int> num;
    rep(i,n) cin>>A[i],num[A[i]]++;
    sort(A.begin(),A.end(),greater<int>());
    rep(i,A.size()){
        num[A[i]]--;
        if(num[A[i]<=0) continue;
        int a=pow(2,int(log2(A[i]))+1)-A[i];
        if(num[a]>0) ans++,num[a]--;
    }
    cout<<ans;
}