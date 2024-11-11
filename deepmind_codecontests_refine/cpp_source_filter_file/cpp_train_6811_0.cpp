#include <bits/stdc++.h>
int MOD = 1000000007;
using namespace std;
long long int a[502];
long long int fact[100002];
bool is_prime[100002];
map<int, int> mymap;
vector<int> v;
void precompute() {
  memset(is_prime, 1, sizeof(is_prime));
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i <= 100002; i++) {
    for (int j = 2; i * j < 100002; j++) {
      is_prime[i * j] = false;
    }
  }
  for (int i = 0; i < 100002; i++) {
    if (is_prime[i]) {
      v.push_back(i);
    }
  }
  fact[0] = 1;
  for (int i = 1; i < 100002; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}
long long int modPow(long long int a, long long int x, long long int p) {
  long long int res = 1;
  while (x > 0) {
    if (x % 2 != 0) {
      res = (res * a) % p;
    }
    a = (a * a) % p;
    x /= 2;
  }
  return res;
}
long long int modInverse(long long int a, long long int p) {
  return modPow(a, p - 2, p);
}
void factorize(long long int x) {
  int n = v.size();
  int c;
  for (int i = 0; i < n && x > 1; i++) {
    c = 0;
    while (x % v[i] == 0) {
      c++;
      x = x / v[i];
    }
    if (mymap.find(v[i]) != mymap.end()) {
      mymap.find(v[i])->second += c;
    } else {
      mymap.insert(pair<int, int>(v[i], c));
    }
  }
  if (x > 1) {
    if (mymap.find(x) != mymap.end()) {
      mymap.find(x)->second += 1;
    } else {
      mymap.insert(pair<int, int>(x, 1));
    }
  }
}
int main() {
  precompute();
  mymap.clear();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    factorize(a[i]);
  }
  long long int ways = 1;
  map<int, int>::iterator it;
  for (it = mymap.begin(); it != mymap.end(); ++it) {
    ways = (ways *
            (fact[mymap[it->first] + n - 1] *
             modInverse((fact[n - 1] * fact[mymap[it->first]]) % MOD, MOD)) %
            MOD) %
           MOD;
  }
  cout << ways << endl;
}
