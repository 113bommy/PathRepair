#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
 int n, A[1000];
 while(1){
  cin >> n;
  if(n==0)break;
  for(int i=0; i<n; i++) cin >> A[i];
  int sum=0;
 for(int i=0; i<n; i++) sum +=A[i];
 double avg=1.0*sum/n;
 double dist=0.0;
 for(int i=0; i<n; i++){
  dist+=(avg-A[i])*(avg-A[i]);
 }
 printf("%lf\n", sqrt(dist/n));
}
return 0;
}
