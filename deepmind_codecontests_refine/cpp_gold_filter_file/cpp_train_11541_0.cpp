#include <bits/stdc++.h>
using namespace std;

int main()
{
int a,b,c; cin>>a>>b>>c;

for(int i = 0 ; i < 100 ; i++)
{
if ((b*i + c)%a == 0)
{
cout<<"YES";
return 0;
}
}
cout<<"NO";
return 0;
}