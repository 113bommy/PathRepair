#include<bits/stdc++.h>
long N,A,B,C,D,E;
int main(){
  std::cin>>N>>A>>B>>C>>D>>E;
  std::cout<<(N-1)/std::min({A,B,C,D,E})+5<<std::endl;
}
