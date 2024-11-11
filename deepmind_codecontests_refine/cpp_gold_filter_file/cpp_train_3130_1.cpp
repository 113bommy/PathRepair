#include<iostream>
using namespace std;
int main(){
int n,num[100];
cin >> n;
for(int a=0; a<n; a++){
cin >> num[a];
}
for(int a=n-1; a>=0; a--){
if(a!=n-1) cout << " ";
cout << num[a];
}
cout <<endl;
return 0;
}
