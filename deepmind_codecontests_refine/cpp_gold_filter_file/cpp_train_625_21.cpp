#include<iostream>
#include<algorithm>
using namespace std;

int main(){
int a,b,c,n;
cin>>a>>b>>c;
n=0;

for(a;a<=b;a++){
if(c%a==0) n++;
}
cout<<n<<endl;
}