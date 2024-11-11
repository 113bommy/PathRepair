#include<bits/stdc++.h>
long N,A,B,C,D,E;
main(){
  std::cin>>N>>A>>B>>C>>D>>E;
  std::cout<<(N-1)/min({A,B,C,D,E})+5<<std::endl;
}
