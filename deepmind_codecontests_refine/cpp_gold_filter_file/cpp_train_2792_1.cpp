#include<iostream>
#include<cstdio>
using namespace std;
 
int main(){
   int n,m,d;
   cin >> n >> m >> d;
 
   if( d !=0){
      printf("%.7f", 2.0 * (n-d) * (m-1) / n / n);
   }else{
      printf("%.7f", 1.0  * (m-1)  / n);
   }
}
