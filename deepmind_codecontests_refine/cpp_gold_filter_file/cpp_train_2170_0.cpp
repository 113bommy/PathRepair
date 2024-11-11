#include<iostream>
#include<cmath>

int main(){
  long n; std::cin>>n;long v =0;for(long i =0;i<n;i++){long f;std::cin >>f;if(f%2==0)v++;}
  long long dd = pow(3,n)-pow(2,v);
  std::cout<<dd;

return 0;
}
