#include<iostream>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
int ans=a*b;
if(a>9||b>9)ans=-1;
cout<<ans<<endl;
return 0;
}
