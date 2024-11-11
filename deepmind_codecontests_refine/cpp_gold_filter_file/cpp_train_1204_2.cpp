#include <bits/stdc++.h>
using namespace std;
bool sieve[100001] = {false};
vector<int> primes;
unordered_map<int, vector<int>> buckets;
unordered_set<int> factors[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i < 100001; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j < 100001; j += i) {
        sieve[j] = true;
      }
    }
  }
  for (int i = 2; i < 100001; i++) {
    if (sieve[i]) {
      for (int prime : primes) {
        if (i % prime == 0) {
          factors[i].insert(prime);
          factors[i].insert(factors[i / prime].begin(),
                            factors[i / prime].end());
          break;
        }
      }
    } else {
      factors[i].insert(i);
    }
  }
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    for (int prime : factors[num]) {
      buckets[prime].push_back(num);
    }
  }
  int max = 1;
  for (auto it = buckets.begin(); it != buckets.end(); it++) {
    int s = it->second.size();
    if (s > max) {
      max = s;
    }
  }
  cout << max << endl;
  return 0;
}
