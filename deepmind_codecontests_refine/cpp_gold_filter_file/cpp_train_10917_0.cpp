#include <iostream>
using namespace std;

int main(){
int a;
int b;
int c;
int d;
int e;
int f;
while(cin>>d>>e){
a=d;
b=e;
while(1){
c=a%b;
a=b;
b=c;
if(b==0){break;}
}
f=d/a*e;
cout << a <<" ";
cout << f <<endl;}}