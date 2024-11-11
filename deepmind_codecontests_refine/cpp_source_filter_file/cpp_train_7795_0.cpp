#include"bits/stdc++.h"
using namespace st;
int main(){
int a[3];
cin>>a[0]>>a[1]>>a[2];
if(a[0]==1&&a[1]==1&&a[2]==0||a[0]==0&&a[1]==0&&a[2]==1){
cout<<"Open"<<endl;
}
else {
cout<<"Close"<<endl;
}
}