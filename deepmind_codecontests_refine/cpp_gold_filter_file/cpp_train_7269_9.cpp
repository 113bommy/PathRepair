#include<iostream>
using namespace std;
int main(){
int n,y,i,j,k;
cin >> n >> y;;
for(i=0;i<=n;i++){
for(j=0;j<=n;j++){
k=n-i-j;
if(k>=0 && 1000*i+5000*j+10000*k==y){
printf("%d %d %d\n",k,j,i);
return 0;
}
}
}
printf("-1 -1 -1\n");
return 0;
}