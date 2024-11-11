#include<iostream>
using namespace std;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
int m,n;
cin>>m>>n;
if(a[m-1]==a[n-1]) cout<<"Yes";
else cout<<"No";
}