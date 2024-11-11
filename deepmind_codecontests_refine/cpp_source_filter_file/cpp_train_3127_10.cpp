#include<iostream>
using namespace std;
int main(){
int a,num[100];
cin >> a;
for(z=0; z<a; z++){
cin >> num[z];
}
for(z=a-1; z>=0; z--){
if(z!=a-1) cout << " ";
cout << num[z];
}
cout <<endl;
return 0;
}
