#include <bits/stdc++.h>
using namespace std;
long long int MAX(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
int GCD(int a, int b) {
  int x = MAX(a, b);
  int y = ((b) ^ (((a) ^ (b)) & -((a) < (b))));
  if (x % y == 0) {
    return y;
  } else {
    return GCD(x % y, y);
  }
}
long long fast_pow(int a, int n) {
  long long result = 1;
  long long power = n;
  long long value = a;
  while (power > 0) {
    if (power & 1) {
      result = result * value;
      result = result % 1000000007;
    }
    value = value * value;
    value = value % 1000000007;
    power /= 2;
  }
  return result;
}
int pow_k(long long int N, long long int K) {
  int count = 0;
  while (N > 1) {
    N /= K;
    count++;
  }
  return count;
}
int count_bit(int N) {
  int count = 0;
  for (int i = 0; i < 32; i++) {
    if (N & (1 << i)) {
      count++;
    }
  }
  return count;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int W, M;
  cin >> W >> M;
  int base[102] = {0};
  long long int N = M;
  int k = 0;
  while (N) {
    base[k] = N % W;
    N /= W;
    k++;
  }
  for (int i = 0; i < k; i++) {
    if (base[i] == 0 || base[i] == 1) {
    } else if (base[i] == W - 1)
      base[i + 1] += 1;
    else if (base[i] == W) {
      base[i] = 0;
      base[i + 1] = 1;
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
