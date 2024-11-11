#include <bits/stdc++.h>
using namespace std;
int main(){
    long long X,A,B;
    cin>>X;
    for(long long i=0;i<10000;i++){
    for(long long j=-65;j<10000;j++){
    A=i*i*i*i*i;
    B=j*j*j*j*j;
    if(A-B==X){
    cout<<i<<" "<<j<<endl;
    goto as;}}}
    as:
    cout<<endl;}
