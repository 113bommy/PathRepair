#include<cstdio>
using namespace std;

int main(){
  int n,t,c,tt,minx=10000;
  scanf("%d %d",&n,&t);
  for(int i=0;i<n;i++){
    scanf("%d %d",&c,&tt);
    if(tt<=t&&min>c)
      minx=c;
  }
  if(min==10000)
    printf("TLE\n");
  else
    printf("%d\n",minx);
}