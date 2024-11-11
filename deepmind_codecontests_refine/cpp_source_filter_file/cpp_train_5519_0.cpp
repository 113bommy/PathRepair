#include<stdio.h>
 
 
int G[101][101], q1[101], q2[101], n;
 
void f(int a, int b){
  int i;
  q1[a] = b;
  for(i = 1; i <= B[a]; i++){
    if(b + 1 < q1[G[a][i]]) f(G[a][i], b + 1);
  }
}
 
int main(){
  int i, j, m;
 
  scanf("%d", &n);
 
  for(i = 1; i <= n; i++){
    q1[i] = 100000000;
    scanf("%d", &m);
    scanf("%d", &q2[m]);
 
    for(j = 1; j <= q2[m]; j++) scanf("%d", &G[m][j]);
  }
 
  f(1, 0);
 
  for(i = 1; i <= n; i++){
    if(q1[i] == 100000000) q1[i] = -1;
  }
 
  for(i = 1; i <= n; i++) printf("%d %d\n", i, q1[i]);
 
  return 0;
}