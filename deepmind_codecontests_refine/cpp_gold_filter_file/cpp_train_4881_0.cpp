#include<stdio.h>
#include<algorithm>
using namespace std;
int p[1000001];
int main(){
for(int i=0;i<1000001;i++)p[i]=1;
p[0]=p[1]=0;
for(int i=2;i<1000001;i++)
if(p[i])
for(int j=i+i;j<1000001;j+=i)
p[j]=0;
for(int i=1;i<1000001;i++)p[i]+=p[i-1];
int a;while(scanf("%d",&a),a){
long long r=0;
while(a--){
int b,c;
scanf("%d%d",&b,&c);
r+=p[min(b+c,1000000)]-p[max(0,b-c-1)]-1;
}printf("%lld\n",r);}}