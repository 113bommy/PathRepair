#include<iostream>
using namespace::std;
int main(){
int n,k,i,j,h=0;
cin>>n>>k;
for(i=0;i<n;i++)
{
    cin>>j;
    if(j>=k){
h++;
    }
}
cout>>h;
}