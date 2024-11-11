#include <bits/stdc++.h>
using namespace std;
const int N = 300001;
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  long long int fact[N];
  vector<pair<int, int> > seq;
  map<int, long long int> freqA;
  map<int, long long int> freqB;
  map<pair<int, int>, long long int> freqSeq;
  seq.clear();
  freqA.clear();
  freqB.clear();
  freqSeq.clear();
  fact[0] = fact[1] = 1;
  for (int i = 2; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int ai;
    int bi;
    cin >> ai >> bi;
    freqA[ai]++;
    freqB[bi]++;
    seq.push_back(make_pair(ai, bi));
    freqSeq[make_pair(ai, bi)]++;
  }
  sort(seq.begin(), seq.end());
  bool unsorted = false;
  for (int i = 1; i < n; i++) {
    if (seq[i - 1].second > seq[i].second) {
      unsorted = true;
      break;
    }
  }
  long long int res = fact[n];
  long long int res1 = 1;
  for (map<int, long long int>::iterator it = freqA.begin(); it != freqA.end();
       it++) {
    res1 = (res1 * fact[(it->second)]) % mod;
  }
  long long int res2 = 1;
  for (map<int, long long int>::iterator it = freqB.begin(); it != freqB.end();
       it++) {
    res2 = (res2 * fact[(it->second)]) % mod;
  }
  long long int res3 = 1;
  if (!unsorted) {
    for (map<pair<int, int>, long long int>::iterator it = freqSeq.begin();
         it != freqSeq.end(); it++) {
      res3 = (res3 * fact[(it->second)]) % mod;
    }
  }
  res = (res - res1 - res2 + mod) % mod;
  if (!unsorted) {
    res = (res + res3) % mod;
  }
  cout << res % mod << endl;
  return 0;
}
