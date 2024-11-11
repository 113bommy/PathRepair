#include <bits/stdc++.h>
using namespace std;
long long N = 1e6;
int arr[1000001];
vector<long long> prime;
void seive() {
  for (int i = 0; i <= N; i++) {
    arr[i] = 1;
  }
  arr[0] = arr[1] = 0;
  for (int i = 2; i <= N; i++) {
    if (arr[i] == 1) {
      prime.push_back(i);
      for (int j = i * 2; j <= N; j += i) {
        arr[j] = 0;
      }
    }
  }
}
int main() {
  seive();
  long long n;
  cin >> n;
  unordered_map<long long, long long> M;
  long long ans = 1;
  for (int i = 0; i < prime.size(); i++) {
    long long p = prime[i];
    if (n == 1) break;
    while (n > 1 && n % p == 0) {
      n /= p;
      M[p]++;
    }
  }
  unordered_map<long long, long long>::iterator it;
  for (it = M.begin(); it != M.end(); it++) {
    long long p = it->first;
    long long ct = it->second;
    if (ct > 0) ans *= p;
  }
  cout << ans;
  return 0;
}
