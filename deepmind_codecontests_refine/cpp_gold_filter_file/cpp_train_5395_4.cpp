#include <bits/stdc++.h>
using namespace std;
int main()
{
int a,b,c;
cin>>a;
for(int i=1;i<=a;)
{b=0;
for(int j=1;j<=i;)
{if(i%j==0)
b++;
j=j+2;}
if(b==8)
c++;
i=i+2;}
cout<<c;
}
