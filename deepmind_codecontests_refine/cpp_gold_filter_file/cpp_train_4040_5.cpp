#include <bits/stdc++.h>
int main()
{
  int N,M;std::cin>>N>>M;
  std::vector<std::vector<int>> W(M+1);
  for (int i=0;i<N;i++){
    int A,B;std::cin>>A>>B;
    if(A<=M){W[A].push_back(B);}
  }
  std::priority_queue<int> Q;
  int ans =0;
  for(int i=0;i<=M;i++){
    for(const int b:W[i]){Q.push(b);}
    if(not Q.empty()){ans+=Q.top(),Q.pop();}
  }
  std::cout<<ans<<std::endl;
}
