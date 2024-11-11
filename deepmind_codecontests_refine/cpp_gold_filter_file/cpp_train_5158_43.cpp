#include <bits/stdc++.h>
using namespace std;
long long factMul[100001];
long long fastModPow(long long base, long long exp, long long p) {
  if (exp == 0) return 1;
  long long res = fastModPow(base, exp / 2, p);
  res = (res * res) % p;
  if (exp % 2 == 0)
    return res;
  else
    return (res * (base % p)) % p;
}
long long modInv(long long a, long long p) { return fastModPow(a, p - 2, p); }
long long digits(long long a) {
  int s = 0;
  while (a > 0) a /= 10, s++;
  return s;
}
int isPrime(long long n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int* sieveOfEra(int n) {
  int* prime = new int[n + 1];
  memset(prime, 0, (n + 1) * sizeof(int));
  prime[2] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (prime[i] != 0)
      continue;
    else {
      for (int j = 2 * i; j <= n; j += i) prime[j] = 1;
    }
  }
  return prime;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long gcdOfArr(long long* arr, int n) {
  long long g = arr[0];
  for (int i = 1; i < n; i++) g = gcd(g, arr[i]);
  return g;
}
void arrDivide(long long* arr, int d, int n) {
  for (int i = 0; i < n; i++) arr[i] /= d;
}
int parseInt(char* arr) {
  int ans = 0;
  int index = 0;
  while (index < strlen(arr)) {
    ans = ans * 10 + arr[index] - 48;
    index++;
  }
  return ans;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long c = (n / 5) * (m / 5);
  for (int i = 1; i < 5; i++) {
    c += ((n + i) / 5) * ((m + (5 - i)) / 5);
  }
  cout << c;
  return 0;
}
