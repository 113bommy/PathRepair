#include<bits/stdc++.h>
int n,r,i,j,a[100];
main(){
scanf("%d",&n);
for(;i<n;)scanf("%d",a+i++);
for(i=0;i<n;i++){
for(j=0;j<i;j++){
if(a[i]<a[j])r++;
}
}
std::sort(a,a+n);
for(i=0;i<n;if(i)printf(" "),printf("%d",a[i++]))
printf("\n%d\n",r);
}