#include <stdio.h>
int main(){
int n,top,low,tot;
long long int tot;
scanf("%d%d",&n,&low);
tot=top=low;
for(int i=1;i<n;i++){
scanf("%d",&temp);
if(temp>top)top=temp;
if(temp<low)low=temp;
tot+=temp;
}
printf("%d %d %d\n",low,top,tot);
}