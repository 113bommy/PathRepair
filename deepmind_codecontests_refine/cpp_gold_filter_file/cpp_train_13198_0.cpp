#include<iostream>
#include<cstdint>
#include<algorithm>

int64_t calc(int64_t a1, int64_t a2, int64_t b1, int64_t b2, int lv, int64_t L) {
  if(lv == 0) return 0;
  int64_t Lb = L/3;
  int64_t bi_a1 = a1/Lb;
  int64_t bi_a2 = a2/Lb;
  int64_t bi_b1 = b1/Lb;
  int64_t bi_b2 = b2/Lb;
  if(bi_a1 == bi_b1 && bi_a2 == bi_b2) {
    return calc(a1%Lb, a2%Lb, b1%Lb, b2%Lb, lv-1, Lb); // same block
  }
  if(bi_a2 == bi_b2) { std::swap(a1, a2); std::swap(b1, b2); }
  // bi_a2 != bi_b2
  while(Lb > 0) {
    bi_a1 = a1/Lb;
    bi_b1 = b1/Lb;
    if(bi_a1 != bi_b1) return std::abs(a1-b1) + std::abs(a2-b2);
    if(bi_a1 == 1 && std::abs(a2/Lb - b2/Lb) > 1) {
      //a1 %= Lb;
      //b1 %= Lb;
      //return std::abs(a2 - b2) + std::min(a1+b1+2, Lb*2-a1-b1);
      int64_t r1 = a1 - (Lb-1) + b1 - (Lb-1);
      int64_t r2 = Lb*2 - a1 + Lb*2 - b1;
      return std::abs(a2-b2) + std::min(r1, r2); 
    }
    a1 %= Lb;
    b1 %= Lb;
    Lb /= 3;
  }
  return std::abs(a2 - b2);
}

int main() {
  int64_t L = 1;
  for(int i = 0; i < 30; ++i) L *= 3;
  int Q; std::cin >> Q;
  for(int i = 0; i < Q; ++i) {
    int64_t a, b, c, d; std::cin >> a >> b >> c >> d;
    std::cout << calc(a-1, b-1, c-1, d-1, 30, L) << std::endl;
  }
  return 0;
}
