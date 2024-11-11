#include <iostream>
using namespace std;
  
int main(){
int a,b,c=0;
while(cin>>a>>b){
a+=b;c=0;
while(a>0){
a/=10;c++;
}
cout<<c<<endl;
}
return 0;
}