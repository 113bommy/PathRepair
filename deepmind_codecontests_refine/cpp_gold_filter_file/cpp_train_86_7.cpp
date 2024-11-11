#include<cstdio>
using namespace std;
int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(a+b==c||b+c==a||a+c==b)
    printf("Yes\n");
  else
    printf("No\n");
}