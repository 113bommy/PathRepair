#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ll int n,a[100001],q,sum=0;
cin>>n;
map<ll int,ll int>m1;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    m1[a[i]]++;
    sum+=a[i];
}
cin>>q;
while(q--)
{
    int a,b;
    cin>>a>>b;
    sum=sum-m1[a]*a;
    sum=sum+m1[a]*b;
    m1[b]=m1[b]+m1[a];
    m1[a]=0;
    cout<<sum<<endl;
}

}
