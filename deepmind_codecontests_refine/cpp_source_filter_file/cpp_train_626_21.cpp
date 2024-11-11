#include<iostream>
#include<algorithm>
using namespace std;

int main(){
int a,b,c,n;
cin>>a>>b>>c;
n=0;

for(int i=a;a<=b;i++){
if(c%i=0) n++;
}
cout<<n<<endl;
}