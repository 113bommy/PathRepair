#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a *= a;
    b >>= 1;
  }
  return res;
}
int main() {
  long long x, d;
  cin >> x >> d;
  vector<long long> vec;
  long long curr = 1;
  while (x) {
    long long y = log2(x + 1);
    for (int i = 0; i < y; i++) vec.push_back(curr);
    curr += d;
    x -= (power(2, y) - 1);
  }
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  cout << endl;
}
