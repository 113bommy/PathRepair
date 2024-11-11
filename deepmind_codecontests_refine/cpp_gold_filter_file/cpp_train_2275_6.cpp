#include <bits/stdc++.h>
using namespace std;
 
int main(){
int n, x,t=0;
cin>>n;
for (int i=0;i<n;i++){
cin>>x;
if (x%2)t++;
}
if (t%2)cout<<"NO\n";else cout<<"YES\n";
}