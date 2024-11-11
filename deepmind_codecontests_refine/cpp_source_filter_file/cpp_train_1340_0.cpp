#include <stdio.h>

long N(long x){
  return (x+1)*(x+2)*(x+3)/6;
}

int main(){
  long n;
  while(~scanf("%ld",&n)){
    if (n > 2000)　n = 4000 - n;
    if (n < 1001) printf("%d\n",N(n));
    else printf("%ld\n", N(n)-(N(2*(n-1000)-n-1001)/2);
  }
  return 0;
}