#include <bits/stdc++.h>

int main(){
  int N; std::cin >> N;
  std::cout << (1000 - (N % 1000)) % 1000 << "\n";

  return 0;
}
