#include<iostream>
using namespace std;
int main(){
int n,a[100];
cin >> n;
for(z=0; z<n; z++){
cin >> a[z];
}
for(z=n-1; z>=0; z--){
if(z!=n-1) cout <<" ";
cout << a[z];
}
cout <<endl;
return 0;
}
