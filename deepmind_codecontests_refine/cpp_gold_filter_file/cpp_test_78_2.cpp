#include <bits/stdc++.h>
using namespace std;
int bits[31];
const int P = 210000;
map<int, int> pf[31];
vector<int> primes;
bool prime[P];
void backdiv(map<int, int>::iterator i, map<int, int> &m, int val,
             vector<int> &v) {
  if (i == m.end()) {
    v.push_back(val);
    return;
  }
  for (int x = 0, val1 = val; x <= i->second; x++, val1 *= i->first) {
    auto j = i;
    j++;
    backdiv(j, m, val1, v);
  }
}
int main() {
  fill(prime + 1, prime + P, true);
  for (int x = 2; x * x <= P; x++) {
    if (prime[x]) {
      for (int y = 2 * x; y < P; y += x) {
        prime[y] = false;
      }
    }
  }
  for (int x = 2; x < P; x++) {
    if (prime[x]) primes.push_back(x);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    fill(bits, bits + 31, 0);
    int n;
    cin >> n;
    bool notallzero = false;
    for (int x = 0, y; x < n; x++) {
      cin >> y;
      notallzero |= (y != 0);
      int bit = 0;
      while (y) {
        bits[bit] += (y & 1);
        y >>= 1;
        bit++;
      }
    }
    if (!notallzero) {
      for (int z = 1; z <= n; z++) {
        cout << z << ' ';
        continue;
      }
      continue;
    }
    for (int x = 0; x < 31; x++) {
      if (bits[x] == 0) continue;
      pf[x].clear();
      int tmp = bits[x];
      for (size_t y = 0;
           y < primes.size() && (primes[y] * primes[y] <= bits[x]); y++) {
        while ((tmp % primes[y]) == 0) {
          pf[x][primes[y]]++;
          tmp /= primes[y];
        }
      }
      if (tmp != 1) pf[x][tmp]++;
    }
    map<int, int> intersect;
    int first = 0;
    while (first < 31 && (bits[first] == 0)) first++;
    for (auto i : pf[first]) {
      int val = i.second;
      for (int y = first + 1; y < 31; y++) {
        if (bits[y] == 0) continue;
        val = min(val, pf[y][i.first]);
      }
      intersect[i.first] = val;
    }
    vector<int> combinations;
    backdiv(intersect.begin(), intersect, 1, combinations);
    sort(combinations.begin(), combinations.end());
    for (int i : combinations) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
