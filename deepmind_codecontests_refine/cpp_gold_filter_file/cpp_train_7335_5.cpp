#include <bits/stdc++.h>
using namespace std;
long long int bigMod(long long int x, long long int y,
                     long long int MOD = 10000007) {
  if (y == 0) return 1 % MOD;
  long long int haha = bigMod(x, y / 2, MOD);
  haha = (haha * haha) % MOD;
  if (y & 1) return (haha * x) % MOD;
  return haha;
}
long long int modInverse(long long int x, long long int MOD) {
  return bigMod(x, MOD - 2, MOD);
}
long long int sieveMama() {
  bool isPrime[1000000];
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  long long int n;
  cin >> n;
  vector<long long int> v;
  for (long long int i = 2; i <= n; i += 2) isPrime[i] = false;
  for (long long int i = 3; i * i <= n; i += 2) {
    if (isPrime[i]) {
      for (long long int m = i * i; m <= n; m += i) {
        isPrime[m] = false;
      }
    }
  }
}
vector<long long int> primeFactorize(long long int n) {
  vector<long long int> primeFactors;
  for (long long int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n = n / i;
      primeFactors.push_back(i);
    }
  }
  if (n > 1) primeFactors.push_back(n);
  return primeFactors;
}
int binarySearch(int arr[], int lo, int hi, int x) {
  if (hi >= lo) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, lo, mid - 1, x);
    return binarySearch(arr, mid + 1, hi, x);
  }
  return -1;
}
int main() {
  long long int n, s = 0, last;
  cin >> n;
  vector<long long int> first, second;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    s += x;
    if (x > 0)
      first.push_back(x);
    else
      second.push_back(abs(x));
    if (i == n - 1) {
      if (x > 0)
        last = 1;
      else
        last = 2;
    }
  }
  if (s > 0)
    cout << "first" << endl;
  else if (s < 0)
    cout << "second" << endl;
  else {
    long long int yo1 = 0, yo2 = 0, size = min(first.size(), second.size());
    for (long long int i = 0; i < size; i++) {
      if (first[i] > second[i]) {
        yo1++;
        break;
      }
      if (first[i] < second[i]) {
        yo2++;
        break;
      }
    }
    if (yo1)
      cout << "first" << endl;
    else if (yo2)
      cout << "second" << endl;
    else {
      if (first.size() > second.size())
        cout << "first" << endl;
      else if (first.size() < second.size())
        cout << "second" << endl;
      else {
        if (last == 1)
          cout << "first" << endl;
        else
          cout << "second" << endl;
      }
    }
  }
}
