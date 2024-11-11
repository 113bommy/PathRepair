#include<iostream>
 
int main() {
  int D, T, S;
  std::cin >> D >> T >> S;
  std::cout << ((D/S) <= T) ? "Yes" : "No" << "\n"; 
  
}