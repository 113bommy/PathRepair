#include<cstdio>
int main(){
  int n,a,b,an=0;
 scanf("%d%d%d,&n,&a,&b);
 for(int i=0;i<n;i++){
  int x;scanf("%d",&x);
  if(x<a||x>=b)an++;
 }
 printf("%d\n",an);
 return 0;
}