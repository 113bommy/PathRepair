#include<iostream>
#include<vector>

int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(auto &e:a)std::cin>>e;
  int g=0;
  for(auto e:a)g^=e;
  for(auto e:a)std::cout<<(g^e)<<"\n";
}
