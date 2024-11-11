#include <bits/stdc++.h>
using namespace std;




int main(){
int N,sum;
sum=0;
cin>>N;
int a[N],b[N];

for(int i=0;i<N;i++){
int s;
cin>>s;
sum+=s;
a[i]=s;
}


b[0]=sum;
for(int j=1;j<=(N-2);j+=2){
b[i]-=a[j%N]*2;
}
for(int i=1;i<N;i++) b[i]=2*a[i-1]-b[i-1];

for(int i=0;i<N;i++) cout<<b[i]<<' ';

 return 0;
}