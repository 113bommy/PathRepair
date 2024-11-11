#include<iostream>

int main(){
  int n,x; std::cin >> n >> x;
  int ans = 1,crt = 0;
  for(int i = 0; i < n; ++i){
    int t; std::cin >> t;
    ans += ((crt += t) <= x);
  }
  std::cout << ans;
}