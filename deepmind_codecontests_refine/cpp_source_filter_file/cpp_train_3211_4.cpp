/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

inline ABS (int x)
{
    return x<0 ? -x : x;
}
int main ()
{
    int i,n,z,w,ara[2005];
    cin>>n>>z>>w;
    for (i=1;i<=n;i++) scanf ("%d",&ara[i]);
    if (n==1) cout<<ABS(w-ara[1])<<endl;
    else cout<<max(ABS(w-ara[n]),ABS(ara[n]-ara[n-1]))<<endl;

    return 0;
}
