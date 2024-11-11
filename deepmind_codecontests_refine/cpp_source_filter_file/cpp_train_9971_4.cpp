#include <bits/stdc++.h>

using namespace std;
long long mi[200005],ma[200005];
int main()
{
    long long n;
    cin>>n;
    for(long long i=0; i<n; i++){
        cin>>mi[i]>>ma[i];
    }
    sort(mi,mi+n);
    sort(ma,ma+n);
    if(n%2==0){
        long long l1=mi[n/2-1],r1=ma[n/2-1],l2=mi[n/2],r2=ma[n/2];
        cout<<l2-l1+r2-r1+(r1-l2)*2+1;
    }else{
        cout<<ma[n/2]-mi[n/2]+1;
    }
    return
}
