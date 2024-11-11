#include <iostream>
using namespace std;
int main(){
int a,b,c,i;
cin>>a>>b>>c;
for(i=a;i<=b;++i)if(i-a<c||i+c>b)cout<<i<<"\n";
cout<<endl;
}
