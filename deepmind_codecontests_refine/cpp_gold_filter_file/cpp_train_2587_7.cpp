#include<bits/stdc++.h>
using namespace std;

int main(){
int i,j,N,K,cnt=0,t;
cin>>N>>K;
for(i=0;i<=N;i++){
for(j=0;j<=N;j++){
t=K-i-j;
if(t>=0&&t<=N)cnt++;
}
}
cout <<cnt<<endl;
}
