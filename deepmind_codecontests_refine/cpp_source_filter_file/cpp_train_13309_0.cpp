#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    ll mn=1e18;
    for (int i=0;i<2;i++) {
        ll sm=0;
        ll cnt=0;
        for (int j=0;j<n;j++) {
            sm+=a[j];
            if ((i+j)%2==0) {
                if (sm<=0) {
                    cnt+=-sm+1;
                    sm=1;
                }
            } else {
                if (sm>=0) {
                    cnt+=sm+1;
                    sm=-1;
                }
            }
        }
        mn=min(mn,cnt);
    }
    cout<<cnt<<endl;
    return 0;
}