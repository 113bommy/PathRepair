#include <bits/stdc++.h>
using namespace std;
void debug(string s) { cout << s << "\n"; }
vector<long long> prime;
void sieve() {
  bool arr[1000008];
  memset(arr, 1, sizeof(arr));
  arr[0] = arr[1] = 0;
  for (int i = 2; i <= sqrt(1000008); i += 1) {
    if (arr[i] == 1) {
      for (int j = i * i; j <= 1000007; j += i) {
        arr[j] = 0;
      }
    }
  }
  for (int i = 2; i <= 1000007; i += 1) {
    if (arr[i] == 1) {
      prime.push_back(i);
    }
  }
}
long long GCD(long long a, long long b) {
  long long c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
long long power(long long a, long long b) {
  long long ans = 1;
  while (b != 0) {
    if (b % 2 == 1) {
      ans *= a;
    }
    a *= a;
    b = b >> 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long k;
  cin >> k;
  if (k > 36) {
    cout << -1;
  } else if (k == 0) {
    cout << 1;
  } else {
    if (k == 1) {
      cout << 4;
    } else {
      if (k % 2 == 1) cout << 4;
      for (int i = 1; i <= k - 1; i += 2) {
        cout << 8;
      }
    }
  }
  return 0;
  ;
}
