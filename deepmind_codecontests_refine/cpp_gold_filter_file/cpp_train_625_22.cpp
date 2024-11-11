#include<iostream>
using namespace std;
int main(){
int a,b,c,z=0;
cin >> a >> b >> c;
for(int x=a; x<=b; x++){
if(c%x==0) z++;
}
cout << z <<endl;
return 0;
}

