#include<iostream>
using namespace std;
int main(){
int n,a,b,c,i;
cin>>n;
for(i=0;i<n;i++){
cin>>a>>b>>c;
if(a*a=b*b+c*c)cout<<"YES"<<endl;else if(b*b=a*a+c*c)cout<<"YES"<<endl;else if(c*c=a*a+b*b)cout<<"YES"<<endl;else cout<<"NO"<<endl;
}
return 0;
}