#include <bits/stdc++.h>
void fast() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
}
long long int gcd(long long int a, long long int b) {
  if (!a) return b;
  return gcd(b % a, a);
}
template <class T>
void print(T a) {
  std::cout << a << "\n";
}
const int MAX = 111111;
int ones(long long int a) {
  int count_ = 0;
  while (a) {
    if (a & 1) {
      count_++;
    }
    a >>= 1;
  }
  return count_;
}
int findBits(long long int a) {
  int count_ = 0;
  while (a) {
    count_++;
    a >>= 1;
  }
  return count_;
}
long long int bits(int n) {
  long long int val = 0;
  while (n) {
    val *= 2;
    val += 1;
    n--;
  }
  return val;
}
std::vector<int> ansArr(30, 1);
void pre() {
  ansArr[1] = 0;
  ansArr[2] = 1;
  ansArr[3] = 1;
  ansArr[4] = 5;
  ansArr[5] = 1;
  ansArr[6] = 21;
  ansArr[7] = 1;
  ansArr[8] = 85;
  ansArr[9] = 73;
  ansArr[10] = 341;
  ansArr[11] = 89;
  ansArr[12] = 1365;
  ansArr[13] = 1;
  ansArr[14] = 5461;
  ansArr[15] = 4681;
  ansArr[16] = 21845;
  ansArr[17] = 1;
  ansArr[18] = 87381;
  ansArr[19] = 1;
  ansArr[20] = 349525;
  ansArr[21] = 299593;
  ansArr[22] = 1398101;
  ansArr[23] = 178481;
  ansArr[24] = 5592405;
  ansArr[25] = 1082401;
}
int main() {
  fast();
  int q;
  pre();
  std::cin >> q;
  long long int a;
  while (q--) {
    std::cin >> a;
    int n = findBits(a);
    int setBits = ones(a);
    if (n != setBits) {
      print(bits(n));
    } else {
      print(ansArr[n]);
    }
  }
}
