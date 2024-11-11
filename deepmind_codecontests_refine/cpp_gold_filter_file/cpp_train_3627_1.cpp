#include<iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n%10==9||n/10==9)cout<<"Yes";
    else cout<<"No";
}