#include<iostream>
using namespace std;
int main(){
int a,b,c;
int d=0;
cin >>a>>b>>c;
for(int i=a;i<=b;i++){
  if(0==c%i){
    d++;
   }
}
cout <<d<<endl;
return 0;
}
    