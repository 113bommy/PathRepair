#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MOD2 = 998244353;
vector<int> bases;
const long long int LLINF = 1ll << 60;
const char en = '\n';
void yes() {
  cout << "YES" << en;
  exit(0);
}
void no() {
  cout << "NO" << en;
  exit(0);
}
template <class T>
void prVec(vector<T> w) {
  cout << w.size() << endl;
  for (int i = 0; i < int(w.size()) - 1; ++i) cout << w[i] << ' ';
  cout << w[w.size() - 1] << endl;
}
long long int raand() {
  long long int a = rand();
  a *= RAND_MAX;
  a += rand();
  return a % (MOD - 7);
}
string to_upper(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
  return a;
}
long long int sti(string a) {
  long long int k = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    k *= 10;
    k += a[i] - '0';
  }
  return k;
}
string its(long long int k) {
  if (k == 0) return "0";
  string a;
  while (k) {
    a.push_back((k % 10) + '0');
    k /= 10;
  }
  reverse(a.begin(), a.end());
  return a;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T, class K>
pair<T, K> mp(T a, K b) {
  return make_pair(a, b);
}
long long int mult(long long int a, long long int b) { return (a * b) % MOD; }
long long int pot(long long int n, long long int k) {
  if (k == 0) return 1;
  long long int a = pot(n, k / 2);
  a = mult(a, a);
  if (k % 2)
    return mult(a, n);
  else
    return a;
}
long long int divide(long long int a, long long int b) {
  return mult(a, pot(b, MOD - 2));
}
long long int sub(long long int a, long long int b) {
  return (a - b + MOD) % MOD;
}
long long int add(long long int a, long long int b) { return (a + b) % MOD; }
bool prime(long long int a) {
  if (a == 1) return 0;
  for (int i = 2; i <= round(sqrt(a)); ++i) {
    if (a % i == 0) return 0;
  }
  return 1;
}
pair<int, int> has(string first) {
  long long int h1 = 0, h2 = 0;
  first = to_lower(first);
  for (char a : first) {
    h1 *= bases[0];
    h1 += a - 'a';
    h1 %= MOD;
    h2 *= bases[1];
    h2 += a - 'a';
    h2 %= MOD2;
  }
  return make_pair(h1, h2);
}
const int N = 300010;
int t;
long long int a, b, c;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
  ios_base::sync_with_stdio(false);
  srand((long long)new char);
  for (int i = 0; i < 10; ++i) bases.push_back(raand() + 13893829);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (c < b)
      cout << -1 << en;
    else {
      long long int rez = 0;
      if (a % 2 != b % 2) {
        if (b % 2 == c % 2)
          --b;
        else
          --a;
        --c;
      }
      rez += c;
      if (b % 2 != c % 2) rez -= 2;
      cout << rez << en;
    }
  }
}
