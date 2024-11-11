#include <bits/stdc++.h>
int main()
{
  int T, C;
  std::cin >> T >> C;
  int ans = 1001;
  for(int i = 0; i < N; i++){
  	int t, c;
    std::cin >>c>>t;
    if(t <=T){ans=std::min(ans, c);}
  }
  std::cout << (ans==1001?"TLE":std::to_string(ans))<<std::endl;  
  return 0;
}
