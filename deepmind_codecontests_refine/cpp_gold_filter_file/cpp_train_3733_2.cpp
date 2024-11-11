#include<iostream>
using namespace std;
 
int main(){
int N;
int T[101];
int sum=0;
cin>>N;
for(int i=1;i<=N;i++){
cin>>T[i];
sum+=T[i];
}
int M;
cin>>M;
for(int i=0;i<M;i++){
int p,x;
cin>>p>>x;
cout<<sum-T[p]+x<<endl;
}
return 0;
}