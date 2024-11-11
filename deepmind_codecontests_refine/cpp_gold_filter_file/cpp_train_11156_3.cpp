#include <bits/stdc++.h>
using namespace std;
vector<bool> primes;
void findPrimes() {
  for (int i = 2; i < 1050; i++) {
    if (!primes[i]) continue;
    for (int j = 2 * i; j < 1050; j += i) {
      primes[j] = false;
    }
  }
}
int nextPrime(int x) {
  while (!primes[x]) x++;
  return x;
}
struct graph {
  int size;
  set<pair<int, int> > adj;
  graph(int n) : size(n) {}
  void addEdge(int a, int b) {
    if (a > b) swap(a, b);
    adj.emplace(a, b);
  }
  void print() {
    cout << adj.size() << endl;
    for (auto& p : adj) {
      cout << p.first + 1 << " " << p.second + 1 << endl;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  primes.resize(1050, true);
  primes[0] = primes[1] = false;
  findPrimes();
  int n;
  cin >> n;
  graph g(n);
  for (int i = 0; i < n; i++) {
    g.addEdge(i, (i + 1) % n);
  }
  if (!primes[n]) {
    int x = nextPrime(n) - n;
    for (int i = 0, aux = 0; aux < x; i += (aux & 1 ? 3 : 1), aux++) {
      g.addEdge(i, (i + 2) % n);
    }
  }
  g.print();
  return 0;
}
