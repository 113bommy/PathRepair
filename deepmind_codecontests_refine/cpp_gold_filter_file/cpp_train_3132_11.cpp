#include<iostream>
using namespace std;
int main(){
int n,num[100];
cin >> n;
for(int a=0; a<n; a++){
cin >> num[a];
}
for(int b=n-1; b>=0; b--){
if(b!=n-1) cout << " ";
cout << num[b];
}
cout <<endl;
return 0;
}
