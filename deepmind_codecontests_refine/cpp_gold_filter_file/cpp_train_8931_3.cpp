#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  double ret=0;
  for(int i=1; i<n+1; i++){
    double a=1.0/n;
    int now=i;
    while(now<k){
      now*=2;
      a/=2;
    }
    ret+=a;
  }
  printf("%.12f\n",ret);
  
}