#include<iostream>
using namespace std;
int main(){
int m,d;
cin>>m>>d;
int ans=0;
for(int i=1;i<=m;i++){
for(int j=1;j<=d;j++){
int d1,d2;
d1=j/10;
d2=j%10;
if(d1>1&&d2>1){
if(d1*d2==i) ans++;
}
}
}
cout<<ans<<endl;
return 0;
}
