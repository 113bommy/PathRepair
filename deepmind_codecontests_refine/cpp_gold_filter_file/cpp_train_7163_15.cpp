#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
int main()
{
cin>>n>>a>>b;
cout<<min(a,b)<<" "<<max(0*1ll,a+b-n);
return 0;
}