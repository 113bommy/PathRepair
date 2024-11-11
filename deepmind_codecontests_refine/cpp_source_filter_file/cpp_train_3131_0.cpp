#include<iostream>
using namespace std;

int main(){
int k,a[100];

cin >>k;

for(int i=0;i<k;i++){
cin >>a[i];
}

for(int i=k-1;i>=0;i--){
if(i!=k-1)cout <<" ";
cout <<a[i]
}
cout <<endl;

return 0;
}