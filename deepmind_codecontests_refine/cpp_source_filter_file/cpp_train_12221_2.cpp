#include <bits/stdc++.h>
using namespace std;
int maxPrime[10000005];
int cnt_prime[10000005];
int primes[10000005];
int cnt_p;
void init() {
  for (int i = 2; i < 10000005; i += 2) maxPrime[i] = 2;
  for (int i = 3; i * i < 10000005; i += 2) {
    if (maxPrime[i] == i || maxPrime[i] == 0) {
      maxPrime[i] = i;
      for (int j = i * 2; j < 10000005; j += i) {
        maxPrime[j] = i;
      }
    }
  }
  for (int i = 2; i < 10000005; i++) {
    if (maxPrime[i] == 0) maxPrime[i] = i;
    if (maxPrime[i] == i) {
      primes[cnt_p++] = i;
    }
  }
}
bool good(long long x) {
  for (int i = 0; i < cnt_p; i++) {
    long long temp = x;
    long long res = 0;
    while (temp) {
      temp /= primes[i];
      res += temp;
    }
    if (res < cnt_prime[primes[i]]) return false;
  }
  return true;
}
int main() {
  long long sum = 0;
  int n;
  int maxx = 0;
  init();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    maxx = max(maxx, a);
    sum += a;
    cnt_prime[a]++;
  }
  for (int i = maxx; i >= 2; i--) {
    cnt_prime[i] += cnt_prime[i + 1];
  }
  for (int i = maxx; i >= 2; i--) {
    cnt_prime[i / maxPrime[i]] += cnt_prime[i];
    if (maxPrime[i] != i) {
      cnt_prime[maxPrime[i]] += cnt_prime[i];
    }
  }
  long long left = maxx, right = sum;
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (good(mid)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left << endl;
  return 0;
}
