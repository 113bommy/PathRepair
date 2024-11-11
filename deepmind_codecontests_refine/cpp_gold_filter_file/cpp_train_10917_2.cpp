#include<iostream>
long long gcd(long long a,long long b){
  if(b==0) return a;
  gcd(b,(a%b));
}

int main() {
  long long i,j,res;
  while(std::cin>>i>>j) {
    res=gcd(i,j);
    std::cout<<res<<" "<<(i*j)/res<<"\n";
  }
}