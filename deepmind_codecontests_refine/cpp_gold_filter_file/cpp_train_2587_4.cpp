#include <iostream>
using namespace std;
int main(){
int k,s,z;
cin>>k>>s;
int n=0;
for(int i=0;i<=k;i++){
for(int j=0;j<=k;j++){
	z=s-i-j; 
	if(s==(i+j+z))
if(z>=0&&z<=k)
n+=1;
}}
cout<<n;
return 0;
}