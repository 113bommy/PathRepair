#include<stdio.h>

int main(){
 int data[10], i, sum, ave;
 for(i = 1, i <= 5, i++){
  scanf("%d", &data[i]);
 if(data[i] < 40) data[i] = 40;
 sum += data[i];
 }
 ave = sum / 5;
 printf("%d", ave);
 return 0;
}
 