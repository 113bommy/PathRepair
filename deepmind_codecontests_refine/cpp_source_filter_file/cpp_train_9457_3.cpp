#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,s,sm=0,mn=100;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>s;
        sm+=s;
        if (m%10)
            mn=min(mn,s);
    }
    if (sm%10)
        cout<<sm<<endl;
    else if (mn!=100)
        cout<<sm-mn<<endl;
    else
        cout<<0<<endl;
    return 0;
}