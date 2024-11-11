#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,a[10005],b[10005],s,ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        s+=b[i]-a[i];
    }
    for (int i = 1; i <= n; i++)
        if (a[i]<b[i]) ans+=(b[i]-a[i]+1)/2;
    if (ans<=s) cout << "Yes";
    else cout << "No";
}