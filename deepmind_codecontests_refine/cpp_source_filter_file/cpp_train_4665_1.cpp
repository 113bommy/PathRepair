#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int> d(n);for(int i=0;i<n;i++)cin>>d[i];sort(d.begin(),d.end());int mid1=(n-1)/2,mid2=mid1+1;cout<<d[mid2]-d[mid1]}