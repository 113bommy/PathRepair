#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, double> a, pair<int, double> b) {
  if (a.second > b.second)
    return 1;
  else
    return 0;
}
void fillPrefixSum(int arr[], int n, int prefixSum[]) {
  prefixSum[0] = arr[0];
  for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + arr[i];
}
void SieveOfEratosthenes(long long n, bool prime[], bool primesquare[],
                         long long a[]) {
  for (long long i = 2; i <= n; i++) prime[i] = true;
  for (long long i = 0; i <= (n * n + 1); i++) primesquare[i] = false;
  prime[1] = false;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
  long long j = 0;
  for (long long p = 2; p <= n; p++) {
    if (prime[p]) {
      a[j] = p;
      primesquare[p * p] = true;
      j++;
    }
  }
}
long long countDivisors(long long n) {
  if (n == 1) return 1;
  bool prime[n + 1], primesquare[n * n + 1];
  long long a[n];
  SieveOfEratosthenes(n, prime, primesquare, a);
  long long ans = 1;
  for (long long i = 0;; i++) {
    if (a[i] * a[i] * a[i] > n) break;
    long long cnt = 1;
    while (n % a[i] == 0) {
      n = n / a[i];
      cnt = cnt + 1;
    }
    ans = ans * cnt;
  }
  if (prime[n])
    ans = ans * 2;
  else if (primesquare[n])
    ans = ans * 3;
  else if (n != 1)
    ans = ans * 4;
  return ans;
}
bool checkLast(long long n) {
  if (n % 10 == 0) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > arrA, arrB;
  int oneCount = 0, evenCount = 0, oddCount = 0, temp;
  vector<int> oneInd, even, odd;
  int count[1001] = {0};
  for (long long i = 0; i < 2 * n; i++) {
    cin >> temp;
    if (temp % 2) {
      oddCount++;
      odd.push_back(i + 1);
    } else {
      evenCount++;
      even.push_back(i + 1);
    }
  }
  if (oddCount == 0) {
    for (int i = 2; i + 1 <= even.size(); i += 2) {
      cout << even[i] << " " << even[i + 1] << "\n";
    }
    return;
  } else if (evenCount == 0) {
    for (int i = 2; i + 1 <= odd.size(); i += 2) {
      cout << odd[i] << " " << odd[i + 1] << "\n";
    }
    return;
  }
  if (oddCount == 1) {
    for (int i = 1; i + 1 <= even.size(); i += 2) {
      cout << even[i] << " " << even[i + 1] << "\n";
    }
  } else if (evenCount == 1) {
    for (int i = 1; i + 1 <= odd.size(); i += 2) {
      cout << odd[i] << " " << odd[i + 1] << "\n";
    }
  } else if (evenCount == oddCount) {
    if (oddCount % 2 != 0) {
      for (int i = 1; i + 1 <= odd.size(); i += 2) {
        cout << odd[i] << " " << odd[i + 1] << "\n";
      }
      for (int i = 1; i + 1 <= even.size(); i += 2) {
        cout << even[i] << " " << even[i + 1] << "\n";
      }
    } else {
      for (int i = 2; i + 1 <= odd.size(); i += 2) {
        cout << odd[i] << " " << odd[i + 1] << "\n";
      }
      for (int i = 0; i + 1 <= even.size(); i += 2) {
        cout << even[i] << " " << even[i + 1] << "\n";
      }
    }
  } else if (oddCount % 2 == 0) {
    for (int i = 2; i + 1 <= odd.size(); i += 2) {
      cout << odd[i] << " " << odd[i + 1] << "\n";
    }
    for (int i = 0; i + 1 <= even.size(); i += 2) {
      cout << even[i] << " " << even[i + 1] << "\n";
    }
  } else if (oddCount % 2 != 0) {
    for (int i = 1; i + 1 <= even.size(); i += 2) {
      cout << odd[i] << " " << odd[i + 1] << "\n";
    }
    for (int i = 1; i + 1 <= even.size(); i += 2) {
      cout << even[i] << " " << even[i + 1] << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test;
  cin >> test;
  while (test--) solve();
}
