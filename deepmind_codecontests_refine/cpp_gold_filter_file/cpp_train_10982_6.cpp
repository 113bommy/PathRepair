#include <bits/stdc++.h>
using namespace std;
vector<long long> pr;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) pr.push_back(p);
}
int main() {
  SieveOfEratosthenes(10000);
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "0";
    return 0;
  }
  set<long long> st;
  for (long long i = 2; i <= n; i++) {
    set<long long> temp;
    for (long long j = 0; pr[j] <= i; j++) {
      if (i % pr[j] == 0) temp.insert(pr[j]);
    }
    if ((long long)((temp).size()) == 1)
      st.insert(i);
    else
      for (auto it : temp) st.insert(it);
  }
  cout << (long long)((st).size()) << "\n";
  for (auto it : st) cout << it << " ";
  return 0;
}
