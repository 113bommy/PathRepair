#include <bits/stdc++.h>
using namespace std;
long long arr[10000000LL];
void sieve() {
  for (__typeof(10000000LL) i = 0; i < 10000000LL; i++) {
    arr[i] = 1;
  }
  arr[0] = arr[1] = 0;
  long long sum = 0;
  long long sq = sqrt(10000000LL);
  for (__typeof(10000000LL) i = 2; i < 10000000LL; i++) {
    if (i < sq && arr[i]) {
      for (long long j = i * i; j < 10000000LL; j += i) {
        arr[j] = 0;
      }
    }
    sum += arr[i];
    arr[i] = sum;
  }
}
long long pal[50];
long long powt[50];
void init() {
  sieve();
  powt[0] = 1;
  for (__typeof(50) i = 1; i < 50; i++) {
    powt[i] = powt[i - 1] * 10;
  }
  long long x = 0;
  pal[0] = x;
  for (__typeof(20) i = 1; i < 20; i++) {
    x += 9 * powt[i - 1];
    pal[2 * i - 1] = x;
    x += 9 * powt[i - 1];
    pal[2 * i] = x;
  }
}
long long fawk(string num, long long dig) {
  for (__typeof(dig / 2) i = 0; i < dig / 2; i++) {
    char a = num[i];
    char b = num[dig - 1 - i];
    if (b < a) {
      long long j = dig - 2 - i;
      while (j >= 0 && num[j] == '0') j--;
      num[j]--;
      j++;
      while (j < dig) {
        num[j] = '9';
        j++;
      }
    }
  }
  long long nd = (dig + 1) / 2;
  num = num.substr(0, nd);
  stringstream second;
  second << num;
  long long actual;
  second >> actual;
  long long ans = actual - powt[nd - 1] + 1;
  if (ans < 0)
    return 0;
  else
    return ans;
}
long long pali(long long n) {
  long long nc = n;
  long long ct = 0;
  while (nc >= powt[ct]) ct++;
  long long ans = pal[ct - 1];
  stringstream second;
  second << n;
  string pass;
  second >> pass;
  ans += fawk(pass, ct);
  return ans;
}
long long p, q;
bool test(long long n) {
  if (q * arr[n] <= p * pali(n)) return true;
  return false;
}
long long bin() {
  long long hi = 10000000LL - 1;
  long long lo = 1;
  long long mid = (hi + lo) / 2;
  long long best = 0;
  while (hi - lo > 1) {
    if (test(mid)) {
      best = max(best, mid);
      lo = mid;
    } else {
      hi = mid;
    }
    mid = (hi + lo) / 2;
  }
  if (test(hi)) best = max(best, hi);
  if (test(lo)) best = max(best, lo);
  return best;
}
int main() {
  init();
  cin >> p >> q;
  long long a = bin();
  long long b = min(a + 10000, 10000000LL - 1);
  for (__typeof(b) i = b; i >= a; i--) {
    if (test(i)) {
      cout << i << endl;
      return 0;
    }
  }
}
