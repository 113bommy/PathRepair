
#include "bits/stdc++.h"
using namespace std;
int main()
{
int n,a,b;
scanf(”%d%d%d”,&n,&a,&b);
int r=0;
for(int i=1;i<=n;i++)
{
intc=0,t=i;
for(int j=0;j<5;j++)c+=t%10,t/=10;
if(a<=c&&c<=b)r+=i;
}
printf(”%d\n”,r);
}