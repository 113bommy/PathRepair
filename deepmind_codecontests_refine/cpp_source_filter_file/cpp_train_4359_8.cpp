#include<iostream>
using namespace std;
bool use[110];
int main(){
int i=3,x,ans
while(i>0){
cin>>x;if(!use[x])++ans;
use[x]=true;
--i;
}
cout<<ans<<endl;
return 0;
}