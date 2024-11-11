#include <bits/stdc++.h>
using namespace std;
bitset<1000100> bs;
vector<int> primes;
void pre() {
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i <= 1000100; i++) {
    if (bs[i]) {
      for (long long j = i * i; j <= 1000100; j += i) bs[j] = 0;
      primes.push_back(i);
    }
  }
}
int p[1000100];
int main() {
  pre();
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int> > > edges;
  int sum = 0;
  for (int i = 0; i < n - 2; i++) {
    edges.push_back({i + 1, {i + 2, 1}});
    sum++;
  }
  int val = *upper_bound((primes).begin(), (primes).end(), sum);
  val = val - sum;
  edges.push_back({n - 1, {n, val}});
  printf("%d %d\n", sum + val, sum + val);
  int need = m - (n - 1);
  for (int i = 0; i < n && need; i++)
    for (int j = i + 1; j < n && need; j++) {
      need--;
      edges.push_back({i + 1, {j + 1, (int)1e9}});
    }
  for (auto e : edges)
    printf("%d %d %d\n", e.first, e.second.first, e.second.second);
  return 0;
}
