#include<iostream>
using namespace std;
int main(){
long a,b=-1,n,res=-1;
cin>>n;
while(n--){
cin>>a;
if(a>b+1)return cout<<-1,0;
res+=a>b?1:a;
b=a;
}
cout<<res;
}
