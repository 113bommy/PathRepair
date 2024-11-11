#include <bits/stdc++.h>
using namespace std;
const int maxv = 1e6 + 5;
bool kt[maxv];
int pp[maxv];
vector<int> pr;
void sieve() {
  for (int i = 2; i <= sqrt(maxv); ++i)
    if (kt[i] == false) {
      for (int j = i + i; j <= maxv; j += i) kt[j] = true;
      pr.push_back(i);
    }
  int ct = 0;
  for (int i = 0; i < maxv; ++i) {
    while (ct < pr.size() && pr[ct] <= i) ++ct;
    pp[i] = ct;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sieve();
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    cout << pp[t] - pp[(int)sqrt(t)] + 1 << "\n";
  }
  return 0;
}
