#include <stdio.h>

bool chk[111];
int x,n;

int main()
{
  scanf ("%d %d",&x,&n);
  for (int i=0;i<n;i++){
int v; scanf ("%d",&v); chk[v] = 1;
  }
  for (int d=0;;d++){
    if (!chk[x-d]){
printf ("%d\n",x-d);
      break;
    }
    if (!chk[x+d]){
printf ("%d\n",x+d);
      break;
    }
  }
return 0;
}
