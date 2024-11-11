#include<iostream>
using namespace std;
int main(){
int n,m,a;
int i;
cin>>n>>m;
for(i=0;i<m;i++){
cin>>a;
n=n-a;
}
if(n<0)n=-1;
cout<<n<<endl;
return 0;
}