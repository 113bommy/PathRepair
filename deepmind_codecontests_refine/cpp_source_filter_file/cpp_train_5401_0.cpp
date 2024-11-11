#include<stdio.h>

int main(){
  const int MAX_V = 100000;
  int prime[MAX_V+1];
  int i, k, v, ans, dif;
  for(i = 2; i <= MAX_V; i++){
    prime[i] = 1;
  }
  for(i = 2; i*i <= MAX_V; i++){
    if(prime[i]){
      for(k = 2 * i; k <= MAX_V; k += i){
        prime[k] = 0;
      }
    }
  }
  while(scanf("%d", &v) != EOF){
    if(v == 0) break;
    for(k = v; k >= 2; k--){
      ans = prime[k];
      if(ans == 1){
        dif = prime[k - 2];
        if(dif == 1){
          printf("%d %d\n", k - 2, k);
          break;
        }
      }
    }
  return 0;
}