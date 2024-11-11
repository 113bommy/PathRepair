#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
int a[10];

for(int i=0;i<10;i++){
scanf(" %d",&a[i]);
}

sort(a,a+10);

for(int i=9;i>=7;i--){
cout << a[i] <<endl;
}

return 0;
}