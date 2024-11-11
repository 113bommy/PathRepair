#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int a,b;
  while(1){
    scanf("%d %d",&a,&b);
    if(a==0 && b==0) break;
    int turi=b-a;
    printf("%d %d %d\n",turi%500/100,turi%1000/500,turi/1000);
  }
}