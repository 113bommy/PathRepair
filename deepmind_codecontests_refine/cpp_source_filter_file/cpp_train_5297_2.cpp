#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
int n,a[10000];
while(true){
scanf("%d",&n);
if(n==0)return 0;
for(int i=0;i<n;i++)scanf("%d",&a[i]);
long long int ans=0;
sort(a,a+n);
for(int i=0;i<n;i++)ans+=(ll)a[i]*(n-1-i);
printf("%lld\n",ans);
}
}