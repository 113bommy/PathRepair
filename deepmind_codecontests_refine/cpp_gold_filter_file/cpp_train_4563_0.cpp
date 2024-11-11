#include <bits/stdc++.h>
using namespace std;
#define N 300010
inline int read() {
    int x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int sum[N];
inline int check(int dat,int n) {
    int Min=0;
    for (int i=2;i<=n;i+=2) 
        if (dat<=sum[i-1]-Min) Min=min(Min,sum[i]);
    return dat<=sum[n]-Min;
}
int main() {
    int n=read(),A=0,B=0;
    for (int i=1;i<=n;i++) {
        int dat=read(); sum[i]=sum[i-1];
        if (i&1) A+=dat,sum[i]+=dat; else B+=dat,sum[i]-=dat;
    }
    if (!(n&1)) return printf("%d %d",max(A,B),min(A,B)),0;
    int l=-1e8,r=1e8,ans=0;
    while (l<=r) {
        int mid=(l+r)>>1;
        if (check(mid,n)) ans=mid,l=mid+1; else r=mid-1;
    }
    printf("%d %d",max(A,B+ans),A+B-max(A,B+ans));
    return 0;
}