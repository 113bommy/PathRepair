#include<iostream>
using namespace std;
int main(){
int N,cnt=0,max=0,i;
cin>>N;
char S[N+1];
for(i=0;i<N;i++){
cin>>S[i];
if(S[i]=='I')cnt++;else cnt--;
if(max<cnt) max=cnt;
}
cout<<max<<endl;
return 0;
}