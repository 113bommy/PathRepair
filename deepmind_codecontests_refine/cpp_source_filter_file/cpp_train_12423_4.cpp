#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool prime[1000001];
void sieve() {
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (int p = 2; p * p <= 1000000; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 1000000; i += p) prime[i] = false;
    }
  }
}
bool cmp(pair<long long, long long>& p1, pair<long long, long long>& p2) {
  if (p1.second == p2.second) {
    return (p1.first < p2.first);
  }
  return (p1.second < p2.second);
}
void solve() {
  string r, s;
  cin >> r >> s;
  sort(s.begin(), s.end(), greater<char>());
  int j = 0, i = 0;
  while (i <= r.size() - 1 && j <= s.size() - 2) {
    if (r[i] < s[j]) {
      r[i] = s[j];
      j++;
      i++;
    } else
      i++;
  }
  cout << r << endl;
}
int main() {
  fast();
  solve();
  return 0;
}
