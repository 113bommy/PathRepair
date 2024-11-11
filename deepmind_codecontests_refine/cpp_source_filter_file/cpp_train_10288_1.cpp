#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int x[n],y[n],h[n];
    tuple<int,int,int> t;
    for (int i=0;i<n;i++) {
        cin>>x[i]>>y[i]>>h[i];
        if (h[i]!=0)
            t=make_tuple(x[i],y[i],h[i]);
    }
    for (int i=0;i<=100;i++)
        for (int j=0;j<=100;j++) {
            int a=abs(j-get<0>(t))+abs(i-get<1>(t))+get<2>(t);
            int f=1;
            for (int k=1;k<;k++)
                f&=max(0,a-abs(j-x[k])-abs(i-y[k]))==h[k];
            if (f) {
                cout<<j<<' '<<i<<' '<<a<<endl;
                return 0;
            }
        }
    return 0;
}