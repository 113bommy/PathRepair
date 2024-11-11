#include<iostream>
using namespace std;

int n;
int a[100001];
int main(){
cin>>n;
int ans=0;
for(int i=0; i<n;i++){
cin>>a[i];
ans=(ans+a[i])%2;
}
if(ans) cout<<"NO"<<endl;
else cout<<"YES"<<endl;
return 0;