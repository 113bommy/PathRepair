#include <bits/stdc++.h>
using namespace std;
int n;
long long a=0;
int main()
{

    cin>>n;

    for(int i=1;i<=n;++i)
    {
        if(i%3 && i%5) a=a+1ll*i;
    }
    cout<<a;
}
