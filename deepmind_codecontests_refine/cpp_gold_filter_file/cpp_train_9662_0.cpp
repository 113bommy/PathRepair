#include <bits/stdc++.h>
using namespace std;

int n;
int h[101];

int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> h[i];
    long long ans=0;
    h[n]=0;
    for(int i=1;i<=n;i++){
        if(h[i-1]>h[i]) ans+=h[i-1]-h[i];
    }
    cout << ans << endl;
}