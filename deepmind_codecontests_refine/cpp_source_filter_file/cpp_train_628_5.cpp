#include<iostream>
using namepsace std;
int main(){
int a,b,c,i=0;
cin >> a >> b >> c;
for(int z=a; z<=b; z++){
if(c%z==0) i++;
}
cout << i <<endl;
return 0;
}
