#include <cstdio>
#define MAX_N 300000
#define MAX_C 300000
int main(){
  int N, Q;
  scanf("%d %d\n", &N, &Q);
  int card[MAX_N];
  bool has_card[MAX_C+1];


  for(int i = 0; i < N; i++){
    scanf("%d", &card[i]);
  //  printf("card %d ", card[i]);
  }
  for(int i = 0; i <= MAX_C; i++){
    has_card[i] = false;
  }
  for(int i = 0; i < N; i++){
    has_card[card[i]] = true;
  }
//  printf("\n");
  for(int i = 0; i < Q; i++){
    int q;
    scanf(" %d", &q);
  //  printf("q = %d\n", q);
    bool found = false;
    for(int init = q-1; init >= 0; init--){
      for(int j = init; j < MAX_C ; j += q){
        if(has_card[j]){
          printf("%d\n", init);
          found = true;
          break;
        }
      }
      if(found){
        break;
      }
    }
  }
  return 0;
}