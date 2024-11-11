#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,i,j;
    cin>>n>>m;
    int A[n];
    int sum=0;
    for(i=0;i<n;i++){scanf("%d",&A[i]);sum+=A[i];}
    sort(A,A+n);
    if(4*m*A[n-m+1]>=sum)printf("Yes\n");
    else printf("No\n");
}