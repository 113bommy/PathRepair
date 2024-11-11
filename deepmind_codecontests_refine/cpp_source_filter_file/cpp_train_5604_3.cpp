#include <iostream>
2.int f(int n){for(int i=3;i<n;i+=2)if(n%i == 0)return 0;return 1;}int main(){int N;std::cin>>N;int c=0,i=0;while(c<N){int n=11+i*10;if(f(n)){std::cout<<n<<" ";c++;}i++;}}
