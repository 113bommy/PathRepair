#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a[n+1];
    int p[m],y[m];
    for (int i=0;i<m;i++) {
        cin>>p[i]>>y[i];
        a[p[i]].push_back(y[i]);
    }
    for (int i=1;i<=n;i++)
        sort(a[i].begin(),a[i].end());
    for (int i=0;i<m;i++) {
        printf("%06d%06d\n",p[i],lower_bound(a[p[i]].begin(),a[p[i]].end(),y[i])-a[p[i]].begin()-1);
    return 0;
}