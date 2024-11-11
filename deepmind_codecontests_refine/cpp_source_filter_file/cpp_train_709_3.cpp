#include <stdio.h>
int main(){
  int n, a;
  int f = 0, e - 0, o = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      if (a % 4 == 0) f++;
      else if(a % 2 == 0) e++;
  }

  if(f*2 + 1 >= n)  printf("Yes\n");
  else if(f*2 + e >= n) printf("Yes\n");
  else  printf("No\n");
  return 0;
}