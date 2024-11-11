#include "bits/stdc++.h"
using namespace std;
#define gs(v) sort(v.begin(),v.end(),greater<int>())
int main(){int n,h,s=0,i=0;cin>>n>>h;
 vector<int>a(n),b(n);for(;i<n;++i)cin>>a[i]>>b[i];
 gs(a),gs(b);for(i=0;i<n&&b[i]>a[0]&&s<h;++i)s+=b[i];
 cout<<i+(s<h)*(h-s+a[0]-1)/a[0];}