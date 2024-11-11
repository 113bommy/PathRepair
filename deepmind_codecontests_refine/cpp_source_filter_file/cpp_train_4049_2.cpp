#include<stdio.h>

int main(){

int G,N;
while(1){
scanf("%d",&G);if(G==0)break;

scanf("%d",&N);
int s,f;
for(int i=0;i<N;i++)
{
scanf("%d %d",&s,&f)
f-=s;
G-=f;
if(G<=0)break;
}
if(G<=0)printf("OK\n");
else printf("%d\n",G);
}
return 0;
}