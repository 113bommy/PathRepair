#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
    int n,z;
    cin>>n>>a[0]>>z;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    if(n==1)cout<<abs(z-a[1]);
    else cout<<max(abs(w-a[n]),abs(a[n]-a[n-1]));
    return 0;
}
