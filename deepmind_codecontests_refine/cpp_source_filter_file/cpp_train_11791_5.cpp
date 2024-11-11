#include <bits/stdc++.h>
long long pows(long long base, long long power, long long mod) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base % mod;
    }
    power >>= 1;
    base = (base * base) % mod;
  }
  return result;
}
long long poww(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base;
    }
    power >>= 1;
    base = (base * base);
  }
  return result;
}
const long long inf = 1e17;
const int N = 3e5 + 10 + 10;
const int M = 6e6 + 10;
const long long mod = 1e9 + 7;
using namespace std;
vector<long long> v;
long long ind = 0;
long long vis[11];
string str = "codeforces";
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= 10; i++) vis[i] = 1;
  long long sum = 0, id = 1;
  while (sum < n) {
    vis[id]++;
    if (id == 10)
      id = 1;
    else
      id++;
    sum = 1;
    for (long long i = 1; i <= 10; i++) sum *= vis[i];
  }
  for (long long i = 0; i <= 9; i++) {
    for (long long j = 1; j <= vis[i + 1]; j++) {
      cout << str[i];
    }
  }
  return 0;
}
