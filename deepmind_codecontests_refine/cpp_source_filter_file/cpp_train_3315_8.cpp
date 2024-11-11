#include <cstdio>
using namespace std;
int main(void){
  int a,b;
  scanf("%d%d",&a,&b);
  puts(a%&&b%3&&(a+b)%3?"Impossible":"Possible");
  return 0;
}