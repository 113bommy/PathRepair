#include<iostream>
int main(){
  int N, A;
  stc::cin >> N >> A;
  if(N%500 <= A) std::cout<<"Yes";
  else std::cout<<"No";
}