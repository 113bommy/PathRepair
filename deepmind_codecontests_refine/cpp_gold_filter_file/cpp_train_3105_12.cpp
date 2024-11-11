#include<bits/stdc++.h>
using namespace std;
int main(){
 int n; cin>>n;
int cnt=0;
int a[n];
for(int i=0;i<n;++i) cin>>a[i];
for(int i=0;i<n;++i){
if(i){
 if(a[i]==a[i-1] && a[i-1]!=-1){ ++cnt; a[i]=-1; }
}
}
cout<<cnt<<endl;
return 0;
}
