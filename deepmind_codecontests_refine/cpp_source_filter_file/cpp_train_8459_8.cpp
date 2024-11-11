#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
const ll MODBASE = 1000000007LL;
const int MAXN = 100010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;
int nt[MAXN], visited[MAXN];
vector<int> primes;
bool foundSmallest = false;
void sieveBase(int n) {
  for (int i = (2); i <= (n); i++) {
    if (nt[i] == 0) {
      nt[i] = i;
      primes.push_back(i);
      for (ll j = (ll)i * i; j <= n; j += i) nt[j] = i;
    }
  }
}
int ask(char ch, int x) {
  cout << ch << ' ' << x << endl;
  int g;
  cin >> g;
  return g;
}
void answer(int x) { cout << "C " << x << endl; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  sieveBase(n);
  int k = int(sqrt(int((primes).size())));
  int res = 1, sum = n;
  memset(visited, 0, sizeof(visited));
  for (int i = (0); i <= (int((primes).size()) - 1); i++) {
    int x = ask('B', primes[i]);
    int num = 0;
    for (int j = primes[i]; j <= n; j += primes[i])
      if (!visited[j]) {
        num++;
        sum--;
        visited[j] = 1;
      }
    if (x != num) {
      for (int w = primes[i]; w <= n; w *= primes[i]) {
        int y = ask('A', w);
        if (y)
          res *= primes[i];
        else
          break;
      }
    }
    if ((i % k == k - 1 || i == int((primes).size()) - 1) && !foundSmallest) {
      int y = ask('A', 1);
      if (y != sum) {
        for (int j = i - k + 1; j <= i; j++) {
          for (int w = primes[j]; w <= n; w *= primes[j]) {
            int z = ask('A', w);
            if (z) {
              res *= primes[j];
              foundSmallest = true;
            } else
              break;
          }
          if (foundSmallest) break;
        }
      }
    }
  }
  answer(res);
  return 0;
}
