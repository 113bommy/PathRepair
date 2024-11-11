#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100007;
const int modulo = 1000000007;
long long a[MAXN], cnt[MAXN];
long long Get_Power(long long a, long long b) {
  if (b == 0) return 1;
  long long res = Get_Power(a, b / 2);
  res = (res * res) % modulo;
  if (b % 2 == 1) res = (res * a) % modulo;
  return res;
}
int main() {
  int N;
  long long prime;
  cin >> N >> prime;
  long long Sum = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    Sum += a[i];
  }
  sort(a + 1, a + N + 1);
  for (int i = 1; i <= N; i++) {
    a[i] = Sum - a[i];
    cnt[i] = 1;
  }
  for (int i = N; i > 1; i--) {
    if (a[i] < a[i - 1] && cnt[i] % prime == 0) {
      cnt[i] /= prime;
      a[i]++;
    }
    if (a[i] == a[i - 1]) {
      cnt[i - 1] += cnt[i];
      continue;
    }
    if (a[i] < a[i - 1]) {
      cout << Get_Power(prime, min(Sum, a[i])) << endl;
      return 0;
    }
  }
  while (cnt[1] % prime == 0) {
    a[1]++;
    cnt[1] /= prime;
  }
  cout << Get_Power(prime, min(Sum, a[1])) << endl;
  return 0;
}
