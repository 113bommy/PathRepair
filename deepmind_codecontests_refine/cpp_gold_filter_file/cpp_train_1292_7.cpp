#include <bits/stdc++.h>
using namespace std;
int main() {
  int K;
  cin >> K;
  int sinir = 2 * K * K;
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 31, 37, 39};
  set<int> mynums;
  int i;
  for (i = 0; i < sizeof(primes) / sizeof(int); i++) {
    mynums.clear();
    int t1 = 1, t2 = 1, t = 1;
    for (int j = 0; j <= i; j++) t *= primes[j];
    for (int j = 0; j <= i / 4; j++) t1 *= primes[j] * primes[i - j];
    for (int j = i / 4 + 1; j < i - i / 4; j++) t2 *= primes[j];
    mynums.insert(t);
    for (int y = 0; y < 30; y++) {
      for (int j = 0; j <= i; j++) {
        for (set<int>::iterator it = mynums.begin(); it != mynums.end(); it++) {
          if (*it * primes[j] <= sinir) {
            mynums.insert(*it * primes[j]);
          }
        }
      }
    }
    if (mynums.size() > K) break;
    if (t1 > 1) mynums.insert(t1);
    if (t2 > 1) mynums.insert(t2);
    for (int y = 0; y < 30; y++) {
      for (int j = 0; j <= i; j++) {
        for (set<int>::iterator it = mynums.begin(); it != mynums.end(); it++) {
          if (*it * primes[j] <= sinir) {
            mynums.insert(*it * primes[j]);
          }
        }
      }
    }
    if (mynums.size() <= K / 2) continue;
    if (mynums.size() > K) break;
  }
  set<int>::iterator it = mynums.end();
  it--;
  cout << *it;
  i = 1;
  for (it--; it != mynums.begin() && i < K; it--, i++) cout << " " << *it;
  cout << endl;
  return 0;
}
