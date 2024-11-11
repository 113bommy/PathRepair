#include<bits/stdc++.h>
using namespace std;
int a[101],sn;
int main()
{
cin>>n;
for(int i=1;i<=n*2;i++)cin>>a[i];
sort(a+1,a+1+2*n);    
for(int i=1;i<=n*2;i+=2)s+=a[i];
cout<<s<<endl;
}