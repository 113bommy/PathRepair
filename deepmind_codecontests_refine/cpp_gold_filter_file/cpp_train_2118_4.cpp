#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
int factor[MAXN];
void sieve() {
  factor[0] = factor[1] = -1;
  iota(factor + 2, factor + MAXN, 0);
  for (int i = 2; i * i < MAXN; i++)
    if (factor[i] == i)
      for (int j = i * i; j < MAXN; j++) factor[j] = min(factor[j], i);
}
vector<pair<int, int> > factorize(int n) {
  vector<pair<int, int> > fs;
  while (n > 1) {
    if (fs.size() == 0 || factor[n] != fs.back().first) {
      fs.push_back(make_pair(factor[n], 1));
    } else {
      ++fs.back().second;
    }
    n /= factor[n];
  }
  return fs;
}
vector<int> divisors(int n) {
  vector<pair<int, int> > fs = factorize(n);
  vector<int> divs(1, 1);
  for (int i = 0; i < fs.size(); i++) {
    int sz = fs[i].second + 1;
    divs.resize(divs.size(), sz * divs.size());
    for (int k = sz; k < divs.size(); k++) {
      divs[k] = divs[k - sz] * fs[i].first;
    }
  }
  return divs;
}
int dp[MAXN];
int is_2(int d, int b) {
  int bp = b;
  int i = 1;
  while (i < 100) {
    if (bp % d == 0) return i;
    bp = (bp * b) % d;
    ++i;
  }
  return 0;
}
bool is_3(int d, int b) { return b % d == 1; }
bool is_11(int d, int b) { return b % d == d - 1; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int b, d;
  cin >> b >> d;
  dp[0] = 11;
  dp[1] = 11;
  for (int i = 2; i <= d; i++) {
    if (is_2(i, b))
      dp[i] = 2;
    else if (is_3(i, b))
      dp[i] = 3;
    else if (is_11(i, b))
      dp[i] = 11;
    else {
      dp[i] = 7;
      for (int j = 2; j < i; j++) {
        if (i % j == 0 && gcd(j, i / j) == 1 && dp[j] != 7 && dp[i / j] != 7) {
          dp[i] = 6;
        }
      }
    }
  }
  cout << dp[d] << "-type\n";
  if (dp[d] == 2) {
    cout << is_2(d, b) << endl;
  }
  return 0;
}
