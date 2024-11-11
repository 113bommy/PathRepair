#include<bits/stdc++.h>
using namespace std;
int n,a[207],i,s;
int main(){
for(cin>>n,i=0;i<n*2;i++) cin>>a[i];
sort(a,a+2*n);
for(i=0;i<2*n;i+=2) s+=a[i];
cout<<s;
}