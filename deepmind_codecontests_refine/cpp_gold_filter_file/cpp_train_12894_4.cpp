#include<bits/stdc++.h>
using namespace std;
int n,a[20000010];
bool x(int i,int j,int k) {
    return a[i]<=k&&a[j]<=k;
}
bool y(int i,int j,int k){
    return a[i]>k&&a[j]>k;
} 
bool check(int a){
    for(int i=0;i<n-1;i++){
        if(y(n+i,n+i+1,a)||y(n-i,n-i-1,a)) return 0;
        if(x(n+i,n+i+1,a)||x(n-i,n-i-1,a)) return 1;
    }
    return x(1,1,a);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
    int l=1,r=2*n-1,mid;
    while(l<r){
	 	mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0; 
}