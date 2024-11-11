#include <iostream>
using namespace std;
int main(){
int k,s,z;
cin>>k>>s;
int c=0;
for(int i=0;i<=k;i++){
for(int j=0;j<=k;j++)
	z=s-i-j; 
if(s==i+j+z){
if(z>=0&&z<=k)
c+=1;}
}
cout<<c;
return 0;
}