#include<bits/stdc++.h>
using namespace std;

int main(){
for(;;){
int n,x;
cin>>n>>x;
if(n==0 && x==0){break;}
int ans=0;
for(int a=1;a<=n;a++){
for(int b=a+1;b<=n;b++){
for(int c=b+1;c<=n;c++){
if(a+b+c==x){ans++;}
}}}
cout<<ans<<endl;
}


return 0;
}
