#include <iostream>
using namespace std;
int main(){
int n;
int g;
while(cin >>n){
g=1;
while(g<1000){
if(n%(2*g)==g&&n!=0;){cout <<g<<" "; n=n-g;}
else if(n%(2*g)==g&&n==g){cout <<g<<endl; n=n-g;}
g=g*2;}
}
}