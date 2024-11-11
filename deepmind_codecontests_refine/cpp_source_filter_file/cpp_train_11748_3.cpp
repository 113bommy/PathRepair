#include<iostream>

using namespace std;

int main(void)
{
  int x,a,b; cin>>x>>a>>b;
  
  if(a>=b){puts("delicious");}
  else if(b-a=<x){puts("safe");}
  else{puts("dangerous");}
  
  return 0;
}


