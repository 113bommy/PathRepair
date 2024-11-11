#include <bits/stdc++.h>
int main(){
  long long N, A, B;
  std::cin >> N >> A >> B;
  std::cout << (N / (A + B)) * A + std::min((N % (A + B)), A)) << std::endl;
}
