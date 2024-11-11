#include <stdio.h>
#include <iostream> 
using namespace std;
const int maxn=105;
int odd[maxn],even[maxn]；
long long n;
int main(){
    int i,num=1;
    scanf("%lld",&n);n++;
    while(n>1){
        if(n&1)odd[++odd[0]]=num++,n--;
        else even[++even[0]]=num++,n/=2;
    }
    printf("%d\n",odd[0]+even[0]<<1);
    for(i=1;i<=odd[0];i++)printf("%d ",odd[i]);
    for(i=even[0];i>=1;i--)printf("%d ",even[i]);
    for(i=odd[0]+even[0];i>=1;i--)printf("%d ",i);
    return 0;
}