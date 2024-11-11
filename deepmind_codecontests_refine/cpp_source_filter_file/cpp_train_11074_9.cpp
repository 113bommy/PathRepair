#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b) { return a > b; }
bool primes[100001];
vector<long long int> *sieve() {
  primes[0] = false;
  primes[1] = false;
  for (long long int i = 2; i * i < 100001; i++) {
    if (primes[i]) {
      for (long long int j = i * i; j < 100001; j += i) {
        primes[j] = false;
      }
    }
  }
  vector<long long int> *prime = new vector<long long int>();
  prime->push_back(2);
  for (long long int i = 3; i < 100001; i += 2) {
    if (primes[i]) {
      prime->push_back(i);
    }
  }
  return prime;
}
int main() {
  memset(primes, 1, sizeof(primes));
  vector<long long int> *prime = sieve();
  long long int N, M;
  cin >> N >> M;
  long long int arr[N][M];
  for (long long int i = 0; i < N; i++) {
    for (long long int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }
  long long int ans[N][M];
  for (long long int i = 0; i < N; i++) {
    for (long long int j = 0; j < M; j++) {
      ans[i][j] = *lower_bound(prime->begin(), prime->end(), arr[i][j]);
      ans[i][j] -= arr[i][j];
    }
  }
  long long int mi = INT_MAX;
  for (long long int i = 0; i < N; i++) {
    long long int sum = 0;
    for (int j = 0; j < M; j++) {
      sum += ans[i][j];
    }
    mi = min(mi, sum);
  }
  for (long long int i = 0; i < M; i++) {
    long long int sum = 0;
    for (long long int j = 0; j < N; j++) {
      sum += ans[j][i];
    }
    mi = min(mi, sum);
  }
  cout << mi << "\n";
  return 0;
}
