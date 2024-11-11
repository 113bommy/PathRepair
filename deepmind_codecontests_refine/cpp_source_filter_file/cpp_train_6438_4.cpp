#include <stdio.h>
using namespace std;
 
int n,m,a[200005],b[200005];
bool f[200005];
 
int main(){
scanf("%d %d",&n,&m);
for(int i=0;i<m;i++){
scanf("%d %d",a+i,b+i);
a[i]--;b[i]--;
if(b[i]==n-1)f[a]=true;
}
for(int i=0;i<n;i++)if(a[i]==0 && f[b[i]]){
printf("POSSIBLE\n");
return 0;
}
printf("IMPOSSIBLE\n");
return 0;
}