#include<iostream>
int main(){int N,D;std::cin>>N>>D;int c=0;while(N>0){N-=2*D+1;c++;}printf("%d\n",c);}
