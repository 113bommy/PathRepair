#include <bits/stdc++.h>
using namespace std;
string rem(string second) {
  if (second[second.size() - 1] == '\r') second.erase(second.size() - 1);
  return second;
}
vector<string> split(string second, char delim) {
  replace(second.begin(), second.end(), delim, ' ');
  stringstream ss(second);
  string buf;
  vector<string> v;
  while (ss >> buf) v.push_back(buf);
  return v;
}
const int MOD = 1000000007;
const double EPS = 1e-6;
const int MAXA = (int)2e5 + 10;
int spf[MAXA];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < MAXA; i++) spf[i] = i;
  for (int i = 4; i < MAXA; i += 2) spf[i] = 2;
  for (int i = 3; i * i < MAXA; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXA; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<int> getFactorization(int x) {
  vector<int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  long long N;
  cin >> N;
  long long A[N];
  for (int i = 0; i < (N); i++) cin >> A[i];
  unordered_map<int, unordered_map<int, int>> times;
  for (int i = 0; i < (N); i++) {
    for (int first : getFactorization(A[i])) {
      times[first][i]++;
    }
  }
  int ans = 1;
  for (auto first : times) {
    if ((int)first.second.size() < N - 1) continue;
    int mn = INT_MAX;
    for (auto z : first.second) mn = min(mn, z.second);
    if ((int)first.second.size() == N - 1)
      for (int i = 0; i < (mn); i++) ans *= first.first;
    else {
      bool rm = 0;
      int cur = INT_MAX;
      for (auto z : first.second) {
        if (z.second == mn && !rm) {
          rm = 1;
          continue;
        }
        cur = min(cur, z.second);
      }
      for (int i = 0; i < (cur); i++) ans *= first.first;
    }
  }
  cout << ans << '\n';
  return 0;
}
