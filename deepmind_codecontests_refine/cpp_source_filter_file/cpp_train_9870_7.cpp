#include<bits/stdc++.h>
int main(void){
int a,b;
  std::cin>> a >> b;
  if(a>=6&&a<=12){b=b/2;}
  elseif(a<6)b=0;
  std::cout<< b <<std::endl;
  return 0;
}