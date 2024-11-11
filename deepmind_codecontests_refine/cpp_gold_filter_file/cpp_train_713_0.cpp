#include<iostream>
int main() {
  int am[7]={0,0,0,0,0,0,0};
  int i,k;
  while(1) {
    std::cin>>i;
    if(i==0)break;
    for(int j=0;j<i;j++) {
      std::cin>>k;
      if(k>60)k=60;
      am[k/10]++;
    }
    for(i=0;i<7;i++) std::cout<<am[i]<<"\n",am[i]=0;
  }
}