#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1000000007
using namespace std;
int main(){
  int X,Y,A;
  int W1,W2,H1,H2,N;
  scanf("%d %d %d",&W1,&H1,&N);
  while(N--){
    scanf(" %d %d %d",&X,&Y,&A);
    if(A==1) W1=max(W1,X);
    if(A==2) W2=min(W2,X);
    if(A==3) H1=max(H1,Y);
    if(A==4) H2=min(H2,Y);
  }
  printf("%d\n",(W1<W2&&H1<H2?(W2-W1)*(H2-H1):0))
  return 0;
}
