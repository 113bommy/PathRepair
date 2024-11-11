#include<bits/stdc++.h>
using namespace std;
int main()
{long long n,x,t,y,i;
 cin>>n;long long a[n];y=0;
 for(i=0;i<n;i++){cin>>a[i];}x=a[0];
for(i=0;i<n;i++)
{if(a[i]>=x)x=a[i];
else y=y+x-a[i];}
cout<<y;
return 0;}