#include <bits/stdc++.h>
using namespace std;
unsigned long long MX = pow(10, 18);
unsigned long long m;
int k;
unsigned long long comb(int n, int r) {
  if (n == r) return 1;
  int counter = 0;
  unsigned long long ans = 1;
  while (counter < r) {
    ans *= (n - counter);
    ans /= (counter + 1);
    counter++;
  }
  return ans;
}
unsigned long long getNum(unsigned long long n) {
  vector<int> bits;
  while (n > 0) {
    bits.push_back(n % 2);
    n = n >> 1;
  }
  int count = 0, i = bits.size() - 1;
  unsigned long long ans = 0;
  while (i >= 0) {
    if (bits[i] == 1) {
      if (count > k) break;
      ans += comb(i, k - count);
      count++;
    }
    i--;
  }
  if (count == k) ans++;
  return ans;
}
unsigned long long calc(unsigned long long n) {
  return getNum(2 * n) - getNum(n);
}
unsigned long long findNum(unsigned long long l, unsigned long long r) {
  if (l >= r) return l;
  unsigned long long mid = (l + r) / 2;
  unsigned long long num = calc(mid);
  if (num >= m) return findNum(l, mid);
  if (num < m) return findNum(mid + 1, r);
}
int main() {
  cin >> m >> k;
  cout << findNum(1, MX) << endl;
}
