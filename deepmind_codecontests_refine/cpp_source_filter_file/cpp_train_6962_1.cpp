#include<iostream>

int main(void){
    int n;
    int a[31]={};
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for(int i=3;i<31;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    while(std::cin>>n){
        if(n==0) break;
        std::cout<<a[i]/3650+1<<std::endl;
    }
    return 0;
}
