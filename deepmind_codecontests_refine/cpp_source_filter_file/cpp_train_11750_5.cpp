#include<bits/stdc++.h> 
using namespace std;
long long n,sum,a[13];
long long dfs(long long x,long long sum,long long sum1)
{
    if(x==1)
        return 2*sum+sum1+a[x]+sum1*10+a[x];
    return dfs(x-1,sum,sum1*10+a[x])+dfs(x-1,sum+sum1,a[x]); 
int main()
{
    cin>>n;
    while(n!=0)
        sum++,a[sum]=n%10,n/=10;
    cout<<dfs(sum,0,0)/2;
    return 0;
}