#include <bits/stdc++.h>
using namespace std;
int prime[1000005];
vector<int> p;
void sieve() {
  memset(prime, 0, sizeof(prime));
  prime[0] = prime[1] = 1;
  for (int i = 4; i < 1000005; i += 2) prime[i] = 1;
  for (int i = 3; i * i < 1000005; i += 2) {
    if (prime[i] == 0) {
      for (int j = i * i; j < 1000005; j += i) prime[j] = 1;
    }
  }
  for (int i = 2; i < 1000005; i++)
    if (prime[i] == 0) p.push_back(i);
}
int main() {
  sieve();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}
