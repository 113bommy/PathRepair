#include<iostream>
using namespace std;
 

int main()
{
  int n, x, i, sum, j, k;
    while(1){
  cin >> n >> x;
  if( n + x == 0) break;
  sum=0;

 for(i=1; i<= n-2;i++){
  for(j=1+i; j<= n-1; j++){
   for(k=1+j; k<= n; k++){
    if(i+j+k==x) 
     sum+=1;
    
    }
   }
  }
   cout << sum << end1;
  }
 
  