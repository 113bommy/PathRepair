#include <iostream>
using namespace std;
int main(){
int a,b,c,i;
cin>>a>>b>>c;
for(i=a;i<=b;++a)if(i-c<=0||i+c>=b)cout<<i<<'\';
cout<<endl;
}