#include <iostream>
using namespace std;
int j,m=0,n;long long k,cnt;
int main() 
{cin>>n>>k;
 int a[n+1],a1[n+1];
 for(int i=1;i<=n;i++){
   cin>>a[i];a1[i]=0;} 
 j=1, 
 while(b[j]==0)
 { b[j]=m+1;
  if(m==k){cout<<j;return 0;}
  j=a[j];m++;} 
 cnt=(k-a1[j]+1)%(m+1-a1[j]); 
 while(cnt--)
 {j=a[j];}
 cout<<j; 
 return 0;}