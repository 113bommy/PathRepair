#include<iostream>
using namespace std;
int main(){
int x;
while(cin>>x){
int ans=1;
for(int i=1;i<=x;i++){
ans+=i;
}
cout<<ans<<endl;
}
return 0;
}