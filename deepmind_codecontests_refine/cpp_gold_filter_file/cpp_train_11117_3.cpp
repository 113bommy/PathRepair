#include <stdio.h>

int n,m,c[200200];

int main()
{
  scanf ("%d %d",&n,&m);
  int s=0,p=0;
  while (m--){
int x; char S[10]; scanf ("%d %s",&x,S);
    if (S[0] == 'A'){
if (c[x] >= 0){
s++; p += c[x];
  c[x] = -1;
}
    }
    else{
if (c[x] >= 0) c[x]++;
    }
  }
  printf ("%d %d\n",s,p);
return 0;
}
