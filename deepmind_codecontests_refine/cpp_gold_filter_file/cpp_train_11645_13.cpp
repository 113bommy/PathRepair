#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b;
    cin>>n>>a>>b;
    if(n>1&&b>=a||n==1&&a==b)cout<<(n-2)*(b-a)+1<<endl;
    else cout<<0<<endl; 
} 